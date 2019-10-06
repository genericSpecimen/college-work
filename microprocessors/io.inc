.model small
.386
.stack 100h

.data
	BUFFSIZE	equ 10
	bufferin	db BUFFSIZE		; max number of characters allowed (including return)
			db ?			; number of characters entered by user
			db BUFFSIZE dup (?)	; characters entered by user
			db '$'
	negflag		db 0			; denotes whether number is negative (0 = +ve, 1 = -ve)
	badip		db 13, 10, 'You must enter 8 digits! $'
	bufferout db BUFFSIZE dup('$')
.code

printstr proc
	push ax		; save current value of ax since ah gets modified

	mov ah, 09h
	; needs offset of string in dx
	int 21h

	pop ax	; restore previous value of ax
	ret
printstr endp

readhex proc
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
		mov ax, 4c00h
		int 21h

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
	mov di, offset bufferout
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

	mov dx, offset bufferout
	call printstr

	; -- restore registers --
	pop bx
	pop cx
	pop di
	; -----------------------

	ret
printhex endp

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
	ret
stoi endp

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

