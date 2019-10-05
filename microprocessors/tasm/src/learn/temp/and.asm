.model small
.stack 100h

.code

main proc
	mov ax, 2
	mov bx, 1
	and ax, bx
	jnz EXIT	; if not zero, then number is odd
	mov cx, 0FFFFh	; this gets executed if number is even
	EXIT:
	mov ax, 4c00h
	int 21h
main endp
end main

