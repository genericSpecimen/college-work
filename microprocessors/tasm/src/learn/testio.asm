.model small
.stack 100h

include io.inc	; printstr, stoi, itos

.data
	num1 dw ?
	num2 dw ?
	msg1 db 13, 10, 'Enter first number: $'
	msg2 db 13, 10, 'Enter second number: $'
	crlf	db 13, 10, '$'
	summsg db 13, 10, 'Sum of numbers: $'
.code

main proc
	mov ax, @data
	mov ds, ax

	mov ax, 000
	call itos
	mov dx, offset bufferout
	call printstr

	mov ax, 4c00h
	int 21h
main endp
end main

