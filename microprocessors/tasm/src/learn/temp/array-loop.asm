.model small
.stack 100h

.data
	datas dw 69, 70, 71, 72, 73, 74, 75, 76, 77, 78

.code
main PROC
	mov ax, seg datas
	mov ds, ax
	mov bx, offset datas
	mov cx, 10
	again:
		mov ah, 02h
		mov dl, [bx]
		int 21h
		inc bx
		inc bx
		loop again
	mov ax, 4c00h
	int 21h
main ENDP
END main

