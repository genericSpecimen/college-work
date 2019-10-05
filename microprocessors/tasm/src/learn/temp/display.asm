.model small
.stack 100h

.data
	msg db 'Hello world$'

.code
main proc
	mov ax, @data
	mov ds, ax

	DISPLAY 'Hello world'

	mov ax, 4c00h
	int 21h
main endp
end main

