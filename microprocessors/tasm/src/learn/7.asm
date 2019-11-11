.model small
.stack 100h

.data
	msg0	db 13, 10, '**** ASCII to Binary conversion ****$'
	ascmsg	db 13, 10, 'Enter an ASCII character: $'
	binmsg	db 13, 10, 'ASCII character in binary: $'
	binary	db 8 dup('0'), '$'	; an ASCII character takes up 8 bits
.code

main proc

	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	mov ah, 09h
	int 21h

	; ---- take ASCII char input ----
	mov ah, 09h
	mov dx, offset ascmsg
	int 21h

	mov ah, 01h
	int 21h
	; -------------------------------
	
	mov ah, 09h
	mov dx, offset binmsg
	mov ah, 09h
	int 21h

	mov bx, 0
	mov bh, al
	mov si, offset binary
	mov cx, 8	; each ASCII character is of 8 bits

	NEXTBIT:
		shl bh, 1	; carry gets highest bit

		mov dl, 30h
		adc dl, 0	; imm data = 0, only carry is added

		mov [si], dl
		inc si
		loop NEXTBIT

	mov dx, offset binary
	mov ah, 09h
	int 21h

	mov ax, 4c00h
	int 21h
main endp
end main
