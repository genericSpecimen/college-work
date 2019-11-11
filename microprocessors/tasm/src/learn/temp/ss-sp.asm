.model small
.stack 200h

.code

main proc

	push 1234h
	pop bx
	mov ax, 4c00h
	int 21h

main endp
end main
