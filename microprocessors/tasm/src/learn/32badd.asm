.model small
.386
.stack 100h

.data

	BUFFSIZE	equ 9
	hexin		db BUFFSIZE
			db ?
			db BUFFSIZE dup(?)
			db '$'
	hexout		db 8 dup('0'), '$'	; 32 bits = 8 hex digits
	msg1		db 13, 10, 'Enter first  hex number (8 digits)  : $'
	msg2		db 13, 10, 'Enter second hex number (8 digits)  : $'
	msg3		db 13, 10, 'Addition       (num1 + num2): $'
	msg4		db 13, 10, 'Subtraction    (num1 - num2): $'
	msg5		db 13, 10, 'Multiplication (num1 * num2): $'
	msg6		db 13, 10, 'Division       (num1 / num2): $'
	msg7		db 13, 10, '	Quotient : $'
	msg8		db 13, 10, '	Remainder: $'
	badip		db 13, 10, 'You must enter 8 digits!$'
	crlf		db 13, 10, '$'

	num1		dd ?
	num2		dd ?
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

	mov si, offset hexin
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


readhex proc
	; converts the string in hexin to a number in ebx

	; -- save registers --
	push eax
	push ecx
	push edx
	push esi
	
	;---------------------
	mov ebx, 0	; result will be stored in ebx

	mov ah, 0Ah
	mov dx, offset hexin
	int 21h

	mov si, offset hexin
	inc si
	mov cl, [si]	; number of characters entered
	cmp cl, 8	; must be 8
	jne BADINPUT

	inc si		; point to first character entered
	READLOOP:
		mov eax, 0
		mov al, [si]
		cmp al, '9'
		jbe conv2	; if 0-9
		cmp al, 'a'
		jb conv1	; jump if below, i.e. if al == A-F
		sub al, 20h	; otherwise characters are a-f, so subtract 20h to make them A-F

		conv1:
			sub al, 7h
		conv2:
			sub al, 30h

		add ebx, eax	; add to ebx
		rol ebx, 4	; move least significant nibble to most significant nibble
		inc si
		loop READLOOP
	ror ebx, 4	; undo last rotate, since we only had to rotate 7 times, but the loop ran for 8 iterations

	jmp EXITREADHEX

	BADINPUT:
		mov dx, offset badip
		call printstr
		jmp EXIT

	EXITREADHEX:
	; -- restore registers --
	pop esi
	pop edx
	pop ecx
	pop eax
	; -----------------------
	ret
readhex endp

printhex proc
	; prints the number in eax in hexadecimal
	; -- save registers --
	push di
	push cx
	push bx
	; --------------------
	mov di, offset hexout
	mov cx, 8	; 8 hex digits

	P1:
		rol eax, 4	; rotate (left) the most significant nibble
		mov bl, al	; store the nibble in bl
		and bl, 0Fh	; only low nibble needed
		add bl, 30h

		cmp bl, 39h	; compare bl with 39h ('9')
		jna P2
		add bl, 7h	; 39h + 7h = 41h ('A')

	P2:
		mov [di], bl
		inc di
		dec cl
		jnz P1

	mov dx, offset hexout
	call printstr

	; -- restore registers --
	pop bx
	pop cx
	pop di
	; -----------------------

	ret
printhex endp

main proc

	mov ax, @data
	mov ds, ax

	; -- take input first number --
	mov dx, offset msg1
	call printstr

	call readhex	; readhex will store the number read in ebx
	mov num1, ebx	; store in num1
	; -----------------------------

	call clearbuffer	; clear buffer so that previous contents are discarded

	; -- take input second number --
	mov dx, offset msg2
	call printstr

	call readhex
	mov num2, ebx	; store in num2
	;-------------------------------


	; --- print addition of numbers ----
	mov dx, offset msg3
	call printstr

	mov eax, num1
	add eax, num2
	call printhex
	;-----------------------------------

	; --- print subtraction of numbers ----
	mov dx, offset msg4
	call printstr

	mov eax, num1
	sub eax, num2
	call printhex
	;--------------------------------------
	
	; --- print multiplication of numbers ----
	mov dx, offset msg5
	call printstr

	mov eax, num1
	mul num2	; 64 bit result in EDX-EAX
	push eax	; save eax

	mov eax, edx
	call printhex	; print EDX

	pop eax		; restore eax
	call printhex	; print EAX
	;--------------------------------------
	
	; --- print division of numbers ----
	mov dx, offset msg6
	call printstr

	mov edx, 0
	mov eax, num1	; 64 bit contents of EDX-EAX are divided by 32 bit operand specified by div instruction
	div num2
	push edx

	mov dx, offset msg7
	call printstr

	call printhex ; 32 bit quotient is in eax, print it

	mov dx, offset msg8
	call printstr

	pop edx
	mov eax, edx	; 32 bit remainder is in edx
	call printhex
	;--------------------------------------
	

	EXIT:
		mov ax, 4c00h
		int 21h
main endp
end main
