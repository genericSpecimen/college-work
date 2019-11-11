.model small
.386
.stack 100h


.data

	BUFFSIZE	equ 10
	bufferin	db BUFFSIZE		; max number of characters allowed (including return)
				db ?			; number of characters entered by user
				db BUFFSIZE dup (?)	; characters entered by user
				db '$'
	badip		db 13, 10, 'You must enter 8 digits! $'
	bufferout db BUFFSIZE dup('$')

	num1 dd ?
	num2 dd ?
	msg0 db 13, 10, '**** 32 bit BCD Addition and Subtraction ****$'
	msg1 db 13, 10, 'Enter first  8 digit decimal number: $'
	msg2 db 13, 10, 'Enter second 8 digit decimal number: $'
	msg3 db 13, 10, 'BCD Addition    (num1 + num2)  : $'
	msg4 db 13, 10, 'BCD Subtraction (num2 - num1)  : $'

.code

printstr proc
	push ax		; save current value of ax since ah gets modified

	mov ah, 09h
	; needs offset of string in dx
	int 21h

	pop ax	; restore previous value of ax
	ret
printstr endp

clearbuffer proc
	; --- save registers --
	push si
	push cx
	; ---------------------

	mov si, offset bufferin
	mov byte ptr [si], BUFFSIZE
	inc si
	mov cx, BUFFSIZE
	inc cx
	dollars:
		mov byte ptr [si], '$'
		inc si
		loop dollars

	; --- restore registers --
	pop cx
	pop si
	; ---------------------

	ret
clearbuffer endp

readdecimal proc
	; converts the string in bufferin to a number in ebx

	; -- save registers --
	push eax
	push ecx
	push edx
	push esi
	
	;---------------------
	mov ebx, 0	; result will be stored in ebx

	mov ah, 0Ah
	mov dx, offset bufferin
	int 21h

	mov si, offset bufferin
	inc si
	mov cl, [si]	; number of characters entered
	cmp cl, 8	; must be 8
	jne BADINPUT

	inc si		; point to first character entered
	READLOOP:
		mov eax, 0
		mov al, [si]
		sub al, 30h ; subtract '0'

		add ebx, eax	; add to ebx
		rol ebx, 4	; move least significant nibble to most significant nibble
		inc si
		loop READLOOP
	ror ebx, 4	; undo last rotate, since we only had to rotate 7 times, but the loop ran for 8 iterations

	jmp EXITREADDECIMAL

	BADINPUT:
		mov dx, offset badip
		call printstr
		mov ax, 4c00h
		int 21h

	EXITREADDECIMAL:
	; -- restore registers --
	pop esi
	pop edx
	pop ecx
	pop eax
	; -----------------------
	call clearbuffer
	ret
readdecimal endp

printdecimal proc
	; prints the number in eax in hexadecimal
	; -- save registers --
	push di
	push cx
	push bx
	; --------------------
	mov di, offset bufferout
	mov cx, 8	; 8 hex digits

	P1:
		rol eax, 4	; rotate (left) the most significant nibble
		mov bl, al	; store the nibble in bl
		and bl, 0Fh	; only low nibble needed
		add bl, 30h

		mov [di], bl
		inc di
		dec cl
		jnz P1

	mov dx, offset bufferout
	call printstr

	; -- restore registers --
	pop bx
	pop cx
	pop di
	; -----------------------

	ret
printdecimal endp

main proc

	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	call printstr

	; --input first number--
	mov dx, offset msg1
	call printstr

	call readdecimal
	mov num1, ebx
	;-----------------------	


	; --input second number--
	mov dx, offset msg2
	call printstr

	call readdecimal
	mov num2, ebx
	;-----------------------	

	mov ecx, 0
	mov edx, num1
	mov ebx, num2

	;------------------------- 32 bit BCD addition -------------------

	; because the DAA instruction functions only with the Al register, this addition must occur 8 bits at a time

	; first add bl and dl
	mov al, bl
	add al, dl
	daa
	mov cl, al

	; now add bh and dh
	mov al, bh
	adc al, dh
	daa
	mov ch, al


	pushf	; push flags since rol instruction affects the carry flag

	; now we need to add the high word, so we rotate the numbers by 16 bits to get high word values into low word
	rol edx, 16
	rol ebx, 16
	rol ecx, 16
	
	popf

	; again add bl and dl
	mov al, bl
	adc al, dl
	daa
	mov cl, al

	; now add bh and dh
	mov al, bh
	adc al, dh
	daa
	mov ch, al

	ror ecx, 16

	mov dx, offset msg3
	call printstr

	mov eax, ecx
	call printdecimal
	;--------------------------------------------------------------------


	;------------------------- 32 bit BCD subtraction -------------------
	mov edx, num1
	mov ebx, num2

	
	; first subtract dl from bl
	mov al, bl
	sub al, dl
	das
	mov cl, al

	; now subtract dh from bh
	mov al, bh
	sbb al, dh
	das
	mov ch, al

	pushf
	; now we need to subtract the high word, so we rotate the numbers by 16 bits to get high word values into low word
	rol edx, 16
	rol ebx, 16
	rol ecx, 16
	popf

	; again subtract dl from bl
	mov al, bl
	sbb al, dl
	das
	mov cl, al

	; now subtract dh from bh
	mov al, bh
	sbb al, dh
	das
	mov ch, al

	ror ecx, 16

	mov dx, offset msg4
	call printstr

	mov eax, ecx
	call printdecimal

	;--------------------------------------------------------------------

	mov ax, 4c00h
	int 21h

main endp
end main

