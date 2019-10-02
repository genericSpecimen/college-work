.model medium
.stack 200h

.code

START:
	mov ax, 0013h
	int 10h

	mov bx, 0a000h
	mov es, bx

	xor di, di	; set di to 0, a faster alternative to mov di, 0
	xor al, al	; set al to 0
	mov cx, 64000

	STARTLOOP:
		stosb	; ES:DI denote where to store the bytes in al
		inc al
	LOOP STARTLOOP

	mov ax, 0100h
	int 21h

	mov ax, 4c00h
	int 21h
END START

