.model small
.stack 100h

.code
main proc
	mov ax, 1000h
	mov bx, 1234h

	xchg ax, bx
	mov ax, 4c00h
	int 21h

main endp
end main
