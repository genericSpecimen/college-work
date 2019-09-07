.MODEL small
.STACK 100h

.DATA

msg DB "Hello World$"

.CODE

main PROC ; procedure block called main
	mov ax, seg msg
	mov ds, ax
	mov dx, offset msg
	mov ah, 09h
	int 21h

	mov ax, 4c00h
	int 21h
main endp ; end procedure block
end main  ; marks EOF, specifying an entry point for your program (optional)

