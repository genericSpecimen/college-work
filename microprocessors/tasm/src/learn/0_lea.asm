.MODEL small
.STACK 256
.DATA
	msg DB "Hello World!$"

.CODE

main PROC
	mov ax, @data
	mov ds, ax
	lea dx, msg
	mov ah, 09h
	int 21h

	mov ax, 4c00h
	int 21h
main ENDP
END main

