.model small
.stack 100h

.data

	BUFFSIZE	equ 10
	bufferout db BUFFSIZE dup('$')

	ARRSIZE equ 10
	arr1	dw 10, 20, 30, 78, 90, 12, 13, 10, 9, 60
	arr2	dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	arr3	dw 10 dup(?)	; stores the addition
	arr4	dw 10 dup(?)	; stores the subtraction
	msg0	db 13, 10, '**** Addition and Subtraction of two arrays **** $'
	msg1	db 13, 10, 'First array: $'
	msg2	db 13, 10, 'Second array: $'
	msg3	db 13, 10, 'Addition: $'
	msg4	db 13, 10, 'Subtraction: $'
	commaspace db ', $'
.code

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
	; requires bx : starting address (offset) of array
	; -- save registers --
	push si
	push cx
	push ax
	push dx
	;---------------------
	
	mov si, 0
	mov cx, ARRSIZE
	printloop:

		mov ax, [bx+si]
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

addarrays proc
	; -- save registers ---
	push ax
	push cx
	push si
	; ---------------------
	; adds arr1 and arr2 and stores it in arr3
	mov cx, ARRSIZE
	shl cx, 1	; since word sized data
	mov si, 0
	ADDLOOP:
		mov ax, arr1[si]
		add ax, arr2[si]
		mov arr3[si], ax
		inc si
		inc si
		loop ADDLOOP
	;-- restore registers --
	pop si
	pop cx
	pop ax
	;-----------------------
	ret
addarrays endp

subarrays proc
	; -- save registers ---
	push ax
	push cx
	push si
	; ---------------------
	; subtracts arr2 from arr1  and stores it in arr4
	mov cx, ARRSIZE
	shl cx, 1	; since word sized data
	mov si, 0
	SUBLOOP:
		mov ax, arr1[si]
		sub ax, arr2[si]
		mov arr4[si], ax
		inc si
		inc si
		loop SUBLOOP
	;-- restore registers --
	pop si
	pop cx
	pop ax
	;-----------------------
	ret
subarrays endp

printstr proc
	push ax		; save current value of ax since ah gets modified

	mov ah, 09h
	; needs offset of string in dx
	int 21h

	pop ax	; restore previous value of ax
	ret
printstr endp

main proc

	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	call printstr

	mov dx, offset msg1
	call printstr

	mov bx, offset arr1
	call printarr

	mov dx, offset msg2
	call printstr

	mov bx, offset arr2
	call printarr

	call addarrays

	mov dx, offset msg3
	call printstr

	mov bx, offset arr3
	call printarr

	call subarrays

	mov dx, offset msg4
	call printstr

	mov bx, offset arr4
	call printarr

	mov ax, 4c00h
	int 21h
main endp
end main
