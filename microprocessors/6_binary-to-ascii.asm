.model small
.stack 100h

.data
	msg0	db 13, 10, '**** Binary to ASCII conversion ****$'
	note	db 13, 10, 'Note: any character other than 0 will be treated as 1 $'
	binmsg	db 13, 10, 'Enter a binary number (8 bits): $'
	ascmsg	db 13, 10, 'ASCII character: $'
	bufferin	db 9	; max number of characters (including return)
			db ?	; number of characters that user has entered
			db 8 dup ('$')
	badip	db 13, 10, 'You need to enter 8 characters! $'
.code

main proc

	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	mov ah, 09h
	int 21h

	; ---- take binary number input ----
	mov ah, 09h
	mov dx, offset note
	int 21h

	mov ah, 09h
	mov dx, offset binmsg
	int 21h


	mov ah, 0Ah
	mov dx, offset bufferin
	int 21h
	;----------------------------------

	mov bx, 0
	mov dx, 128
	mov si, offset bufferin
	inc si	; point to number of characters entered
	mov cl, [si]
	cmp cl, 8
	jne BADINPUT	; if number of characters != 8, jump to BADINPUT

	inc si	; point to first character entered
	READCHAR:
		mov al, [si]
		sub al, 30h
		cmp al, 0
		je ZERO
		add bx, dx	; add the weight if character is one
		ZERO:
		shr dx, 1	; next weight = weight / 2
		inc si
		loop READCHAR
	jmp OK

	BADINPUT:
		mov ah, 09h
		mov dx, offset badip
		int 21h
		jmp EXIT

	
	OK:
	mov ah, 09h
	mov dx, offset ascmsg
	mov ah, 09h
	int 21h

	mov ah, 02h
	mov dl, bl
	int 21h

	
	EXIT:
		mov ax, 4c00h
		int 21h
main endp
end main
