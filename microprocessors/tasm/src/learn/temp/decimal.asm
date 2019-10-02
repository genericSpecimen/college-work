.model small
.stack 100h

.data
	num	dw 255
.code

printnum proc

; AX = value to print
	mov cx, 0
	cycle1: ; push numbers onto stack
		mov dx, 0
		cmp ax, 0
		je cycle2

		mov bx, 10
		div bx
		push dx
		inc cx
		jmp cycle1
		

	cycle2:	; pop and output
		cmp cx, 0
		je exitfunc

		pop dx
		add dx, 30h
		mov ah, 02h
		int 21h

		loop cycle2

	exitfunc:
		ret 
	
printnum endp

main proc
	mov ax, @data
	mov ds, ax
	mov ax, num
	call printnum

	mov ax, 4c00h
	int 21h

main endp
end main
