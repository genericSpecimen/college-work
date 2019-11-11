.model tiny

.code

main proc

	mov ax, 0

	mov al, 0ffh
	mov bl, 2
	imul bl

	mov ax, 4c00h
	int 21h

main endp
end main

