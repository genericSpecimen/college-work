.MODEL small
.STACK 256
.DATA
	msg0 DB "Enter a lower case letter: $"
	msg1 DB 13, 10, "You have entered: $"
.CODE

main PROC
	; initialise DS to address of data segment
	mov ax, @data
	mov ds, ax
	
	; print msg0
	mov ah, 09h
	mov dx, offset msg0
	int 21h

	; read character (the character read is put in al)
	mov ah, 01h
	int 21h

	; print msg1
	mov ah, 09h
	mov dx, offset msg1
	int 21h

	; print character entered
	mov ah, 02h
	mov dl, al
	int 21h

	; terminate with exit code 
	mov ax, 4c00h
	int 21h
main ENDP
END main

