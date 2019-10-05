.model small
.stack 100h

.data

	bufferout db 6 dup('$')
.code
main proc

	mov ax, @data
	mov ds, ax

	mov ax, 10000

	; itos: integer to string
	; converts value of ax to a string
	; algo:
	;	1. push each digit (starting from LSD) onto stack by dividing by 10 and pushing the remainder
	;	2. pop each digit, add 30h, and store it in string

	mov cx, 0	; keep track of number of digits pushed onto stack, used during pop cycle
	pushi:	; push each digit onto stack
		mov dx, 0	; required for division
		mov bx, 10	; divide by 10
		div bx

		push dx	; remainder is in dx
		inc cx
		cmp ax, 0	; if ax is zero, then we are done pushing (or ax was zero to begin with)
		je retrieve

		jmp pushi

	retrieve:
		mov si, offset bufferout	; output string is to be stored in bufferout
	popi:	; pop each digit and store it in bufferout

		pop dx		; pop into dx
		add dl, 30h	; convert to ASCII
		mov [si], dl	; write at string index si
		inc si
		loop popi	; loop until cx == 0

	exititos:
		mov byte ptr [si], '$'	; so that contents of previous string are not included

	mov dx, offset bufferout
	mov ah, 09h
	int 21h

	mov ax, 4c00h
	int 21h

main endp
end main
