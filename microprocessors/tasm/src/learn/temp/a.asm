.model small
.stack 100h

.code

main proc

	mov ax, @data
	mov ds, ax

	mov ah, 02h
	mov dl, 254
	int 21h

	mov ax, 4c00h
	int 21h

main endp
end main

