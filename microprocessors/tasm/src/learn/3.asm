.model small
.stack 100h

.data

	BUFFSIZE	equ 10
	bufferin	db BUFFSIZE		; max number of characters allowed (including return)
				db ?			; number of characters entered by user
				db BUFFSIZE dup (?)	; characters entered by user
				db '$'
	negflag		db 0			; denotes whether number is negative (0 = +ve, 1 = -ve)
	bufferout db BUFFSIZE dup('$')

	msg			db 13, 10, '**** Sorting an array using Bubble Sort **** $'
	ARRSIZE 	equ 10
	arr			dw 23, 67, 1, 2, 90, 11, 21, 89, 100, 0
	original	db 13, 10, 'Original array: $'
	sorted		db 13, 10, 'Sorted array: $'
	commaspace	db ', $'

.code

printstr proc
	push ax		; save current value of ax since ah gets modified

	mov ah, 09h
	; needs offset of string in dx
	int 21h

	pop ax	; restore previous value of ax
	ret
printstr endp

itos proc
	; itos: integer to string
	; converts value of ax to a string
	; algo:
	;	1. push each digit (starting from LSD) onto stack by dividing by 10 and pushing the remainder
	;	2. pop each digit, add 30h, and store it in string

	; -------- saving register values -------
	push bx
	push cx
	push dx
	push si
	; ---------------------------------------

	mov si, offset bufferout	; output string is to be stored in bufferout

	; --- test if number is negative or not ---
	test ax, ax
	jns POSITIVE
	mov byte ptr [si], '-'	; display minus if negative 
	inc si
	neg ax	; make it positive
	POSITIVE:
	;------------------------------------------

	mov cx, 0	; keep track of number of digits pushed onto stack, used during pop cycle
	pushi:	; push each digit onto stack
		mov dx, 0	; required for division
		mov bx, 10	; divide by 10
		div bx

		push dx	; remainder is in dx
		inc cx
		cmp ax, 0	; if ax is zero, then we are done pushing (or ax was zero to begin with)
		je retrieve
		jmp pushi

	retrieve:
	popi:	; pop each digit and store it in bufferout

		pop dx		; pop into dx
		add dl, 30h	; convert to ASCII
		mov [si], dl	; write at string index si
		inc si
		loop popi	; loop until cx == 0

	exititos:
		mov byte ptr [si], '$'	; so that contents of previous string are not included
	; ------- restore register values --------
	pop si
	pop dx
	pop cx
	pop bx
	; -----------------------------------------
	ret
itos endp

printarr proc
	; -- save registers --
	push si
	push cx
	push ax
	push dx
	;---------------------
	
	mov si, 0
	mov cx, ARRSIZE
	printloop:

		mov ax, arr[si]
		call itos
		mov dx, offset bufferout
		call printstr

		mov dx, offset commaspace
		call printstr

		inc si
		inc si
		loop printloop
	; -- restore registers --
	pop dx
	pop ax
	pop cx
	pop si
	; -----------------------
	ret
printarr endp

sort proc
	; -- save registers --
	push ax
	push bx
	push cx
	push dx
	push di
	push si
	; --------------------

	mov cx, 0	; counter for outer loop
	mov si, ARRSIZE
	sub si, 2
	shl si, 1	; max index pair to compare == (ARRSIZE-2)*2 (since data is word sized)
	outerloop:
		
		cmp cx, ARRSIZE	; if counter == size
		je exit
		mov di, 0	; counter for inner loop

		innerloop:
			cmp di, si
			jg innerdone

			mov ax, arr[di]
			mov bx, arr[di+2]
			cmp ax, bx
			jle NOSWAP
			xchg ax, bx
			mov arr[di], ax
			mov arr[di+2], bx
			NOSWAP:
			
			add di, 2
			jmp innerloop
		innerdone:
			inc cx
			jmp outerloop
			
	exit:
		; -- restore registers --
		pop si
		pop di
		pop dx
		pop cx
		pop bx
		pop ax
		; -----------------------
		ret 
sort endp

main proc
	mov ax, @data
	mov ds, ax

	mov dx, offset msg
	call printstr

	; -- print original array ---
	mov dx, offset original
	call printstr
	call printarr
	; ---------------------------

	call sort

	; -- print sorted array ---
	mov dx, offset sorted
	call printstr
	call printarr
	; ---------------------------

	mov ax, 4c00h
	int 21h
main endp
end main
