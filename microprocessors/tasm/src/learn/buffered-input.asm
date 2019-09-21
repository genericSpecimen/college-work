.model small
.stack 100h

.data
	string	db 6	; max number of characters allowed
		db ?	; number of characters entered by user
		db 6 dup (?)	; characters entered by user
	num	dw ?
.code
main proc
	mov ax, @data
	mov ds, ax

	mov ah, 0Ah
	mov dx, offset string
	int 21h

	; store number of characters entered in cx==cl
	mov si, offset string
	inc si
	mov cl, [si]
	mov ch, 0
	add si, cx	; si now points to LSD

	; convert the string to number

	mov bx, 0	; stores the number
	mov bp, 1	; (1, 10, 100, 1000....)

	CONVERT_CHAR:
		mov al, [si]	; character to process
		sub al, 30h	; al - '0'
		mov ah, 0	; clear ah, now ax == al
		mul bp		; ax = ax*bp
		add bx, ax	; add result to BX

		mov ax, bp	; current weight
		mov bp, 10	; multiply current weight by 10
		mul bp		; ax = ax * bp
		mov bp, ax	; store new current weight
		dec si		; next digit to process
		loop CONVERT_CHAR

	mov num, bx

	mov si, offset string
	mov cx, 6
	six_dollars:
		mov bl, '$'
		mov [si], bl
		inc si
		loop six_dollars

	mov ax, num
	mov bx, 10
	mov cx, 0
	cycle1:
		mov dx, 0
		div bx	; ax = quotient, dx = remainder
		push dx
		inc cx
		cmp ax, 0
		jne cycle1

	cycle2:
		pop dx
		add dl, 30h
		mov [si], dl
		inc si
		loop cycle2

	mov ah, 09h
	mov dx, offset string
	int 21h

	mov ax, 4c00h
	int 21h
main endp
end main

