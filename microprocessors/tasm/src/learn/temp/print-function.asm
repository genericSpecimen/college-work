.model tiny
.stack 100h

.data
	key db ?
	msg db 'hello world$', 13, 10

.code

printnum proc

	push bp
	mov bp, sp

	mov dl, [bp+4]
	mov ah, 02h
	int 21h

	mov sp, bp
	pop bp
	ret

printnum endp

printstring proc

	push bp
	mov bp, sp

	mov dx, [bp+4]
	mov ah, 09h
	int 21h

	mov sp, bp
	pop bp
	ret

printstring endp

main proc

	mov al, 69
	mov key, al
	push word ptr key
	call printnum

	mov ax, @data
	mov ds, ax

	push offset msg
	call printstring

	mov ax, 4c00h
	int 21h

main endp
end main
