.model small
.stack 100h

.data
	BUFFSIZE	equ 7	; reserve one space for '-' as well in case number is negative
	bufferin	db BUFFSIZE		; max number of characters allowed (including return)
			db ?			; number of characters entered by user
			db BUFFSIZE dup (?)	; characters entered by user
			db '$'
	negflag		db 0			; denotes whether number is negative (0 = +ve, 1 = -ve)
	bufferout db BUFFSIZE dup('$')

.code

main proc
	mov ax, @data
	mov ds, ax

	mov ah, 0Ah
	mov dx, offset bufferin
	int 21h

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

	mov ax, 4c00h
	int 21h
main endp
end main
