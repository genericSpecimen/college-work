.model small
.386
.stack 100h

.data

	ascii db 8 dup('0'), '$'
		

.code

main proc

	mov ax, @data
	mov ds, ax

	mov eax, 16

	mov di, offset ascii
	mov cx, 8

	P1:
		rol eax, 4	; 1 nibble
		mov bl, al	; store in bl
		and bl, 0Fh	; need only low nibble
		add bl, 30h	; convert to ascii

		cmp bl, 39h	; compare bl with '9'
		jna P2
		add bl, 7h	; 39h + 7h = 41h ('A')
	P2:
		mov [di], bl
		inc di
		dec cl
		jnz P1

	mov dx, offset ascii
	mov ah, 09h
	int 21h

	mov ax, 4c00h
	int 21h
main endp
end main
