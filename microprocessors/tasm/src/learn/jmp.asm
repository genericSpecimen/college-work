.model small

.data
        table   dw ONE
                dw TWO
                dw THREE
	crlf db 13, 10, '$'
.code

.startup

TOP:    mov ah, 1
        int 21h

	push ax
	mov dx, offset crlf
	mov ah, 09h
	int 21h
	pop ax
        sub al, 31h
        jb TOP

        cmp al, 2
        ja TOP

        mov ah, 0
        add ax, ax

        mov si, offset table
        add si, ax
        mov ax, [si]
        jmp ax

	
ONE:    mov dl, '1'
        jmp BOT
TWO:    mov dl, '2'
        jmp BOT
THREE:  mov dl, '3'

BOT:
	mov ah, 02h
        int 21h

        mov ax, 4c00h
        int 21h
end

