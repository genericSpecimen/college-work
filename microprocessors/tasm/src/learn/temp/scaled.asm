.model small
.386 ; tlink /3 file.obj
.stack 100h

.data
	datas dw 69, 70, 71, 72, 73, 74, 75, 76, 77, 78

.code
main PROC
	mov ax, seg datas
	mov ds, ax
	
	mov ebx, offset datas
	mov ecx, 2
	
	mov ah, 02h
	mov dl, [ebx + 2 * ecx]
	int 21h
	
	
	mov ax, 4c00h
	int 21h
main ENDP
END main

