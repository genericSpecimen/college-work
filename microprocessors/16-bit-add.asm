.model small
.stack 100h

include io.inc

.data
	msg1 db 'Enter first number: $'
	msg2 db 'Enter second number: $'
	num1 dw ?
	num2 dw ?
	sum db 'Sum: $'

.code
main proc
	mov ax, @data
	mov ds, ax

	; input first number
	mov dx, offset msg1
	call printstr
	
	call input
	mov num1, bx
	call printcrlf
	
	; input second number
	mov dx, offset msg2
	call printstr
	
	call input
	mov num2, bx
	call printcrlf


	; print sum
	mov dx, offset sum
	call printstr
	
	mov ax, num1
	add ax, num2
	call output ; requires number in ax

	mov ax, 4c00h
	int 21h

main endp
end main
