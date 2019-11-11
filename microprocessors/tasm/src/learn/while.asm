.model small
.data

	crlf	db 13, 10, '$'
	buf	db 256 dup(?)

.code
main proc

	mov ax, @data
	mov ds, ax

	mov es, ax	; STOSB uses ES:[DI] to store data, but here ES == DS
	cld		; auto increment di

	mov di, offset buf
	mov al, 00h

GETCHAR:
	cmp al, 0Dh
	je DONE
	mov ah, 1
	int 21h
	stosb
	jmp GETCHAR

DONE:
	mov byte ptr[di-1], '$'
	mov dx, offset crlf
	mov ah, 09h
	int 21h

	mov dx, offset buf
	mov ah, 09h
	int 21h

	mov ax, 4c00h
	int 21h
main endp
end main

