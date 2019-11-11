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
	
	ARRSIZE		equ 10
	arr		dw 11, 2, 33, 48, 51, 100, 267, 89, 112, 69
	key 		dw ?
	msg0		db 13, 10, '**** Linear search **** $'
	arrmsg		db 13, 10, 'The array is: $'
	msg1		db 13, 10, 'Enter element to search: $'
	search		db 13, 10, '=> Searching for: $'
	foundmsg	db 13, 10, '=> Found at index $'
	notfoundmsg 	db 13, 10, '=> Not found$'
	crlf		db 13, 10, '$'
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

stoi proc
	; stoi: string to integer
	; converts string in buffinput to an integer which will be stored in ax

	;------- save register values -------
	push ax
	push cx
	push dx
	push bp
	push si
	; -----------------------------------

	; Format of DOS input buffer:
	; Offset  Size    Description     (Table 01344)
	; 00h    BYTE    maximum characters buffer can hold
	; 01h    BYTE    (call) number of chars from last input which may be recalled
	; (ret) number of characters actually read, excluding CR
	; 02h  N BYTEs   actual characters read, including the final carriage return

	mov si, offset bufferin
	inc si		; point to number of characters entered
	; --- check if first character is minus ---
	inc si		; point to first character
	mov al, [si]
	cmp al, '-'	; if character is minus, we need to negate the number
	jne NOTMINUS
	mov negflag, 1	; set negflag to 1 since number is negative
	NOTMINUS:
	dec si		; point back to number of characters
	;--------------------------------------------
		
	mov cl, [si]	; num of chars entered
	mov ch, 0	; make cx == cl

	; -- if there was a minus, we don't have to consider that character in calculation
	cmp negflag, 1
	jne SAMECX
	dec cx	; decrement cx since there is one less character ('-') to deal with
	inc si
	SAMECX:

	add si, cx	; make si point to LSD

	mov bx, 0	; stores the result
	mov bp, 1	; multiply by (1, 10, 100, ...)
	
	CONVERT_CHAR:

		mov al, [si]	; character to process
		sub al, 30h	; al - '0'
		mov ah, 0	; make ax == al

		mul bp		; ax = ax*bp
		add bx, ax	; add result

		mov ax, bp
		mov bp, 10
		mul bp		; multiply current weight by 10
		mov bp, ax	; new weight

		dec si		; next digit
		loop CONVERT_CHAR
	
	cmp negflag, 1	; is number -ve?
	jne POS		; if no, then there is no need to negate the number we have read
	neg bx		; else negate the contents of bx
	mov negflag, 0	; clear negflag
	POS:

	; -- restore registers --
	pop si
	pop bp
	pop dx
	pop cx
	pop ax
	; -----------------------
	call clearbuffer
	ret
stoi endp

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

linearsearch proc 
	; --- save registers ---
	push si
	push cx
	push ax
	push bx
	push dx
	; ----------------------


	mov si, 0	; starting index of search is 0
	mov cx, ARRSIZE	; number of elements in array
	mov ax, key	; store key in ax 
	LSLOOP:
		mov bx, arr[si]	; copy array element to bx
		cmp bx, ax
		je LSFOUND
		inc si
		inc si
		loop LSLOOP

	LSNOTFOUND:
		mov dx, offset notfoundmsg
		call printstr
		jmp LSEXIT
	LSFOUND:
		mov dx, offset foundmsg
		call printstr
		mov ah, 02h
		shr si, 1
		mov dx, si
		add dl, 30h
		int 21h

	LSEXIT:
	; --- restore contents of registers ---
	pop dx
	pop bx
	pop ax
	pop cx
	pop si
	; -------------------------------------
	ret
linearsearch endp

main PROC
	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	call printstr

	mov dx, offset arrmsg
	call printstr
	call printarr

	;----take input of search key --
	mov dx, offset msg1
	call printstr

	mov ah, 0ah
	mov dx, offset bufferin
	int 21h

	call stoi	; convert input to integer (which gets stored in bx)
	;-------------------------------

	mov key, bx	; store in key

	;----- print "searching for: key"---
	mov dx, offset search
	call printstr

	mov ax, key
	call itos	; convert integer to string (which gets stored in bufferout)

	mov dx, offset bufferout
	call printstr
	;----------------------------------
	
	call linearsearch

	EXIT:
		mov ax, 4c00h
		int 21h
main endp
end main
