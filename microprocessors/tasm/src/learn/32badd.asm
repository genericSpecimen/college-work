.model small
.386
.stack 100h

include io.inc

.data

	msg1		db 13, 10, 'Enter first  hex number (8 digits)  : $'
	msg2		db 13, 10, 'Enter second hex number (8 digits)  : $'
	msg3		db 13, 10, 'Addition       (num1 + num2): $'
	msg4		db 13, 10, 'Subtraction    (num1 - num2): $'
	msg5		db 13, 10, 'Multiplication (num1 * num2): $'
	msg6		db 13, 10, 'Division       (num1 / num2): $'
	msg7		db 13, 10, '	Quotient : $'
	msg8		db 13, 10, '	Remainder: $'
	badip		db 13, 10, 'You must enter 8 digits!$'
	crlf		db 13, 10, '$'

	num1		dd ?
	num2		dd ?
.code

main proc

	mov ax, @data
	mov ds, ax

	; -- take input first number --
	mov dx, offset msg1
	call printstr

	call readhex	; readhex will store the number read in ebx
	mov num1, ebx	; store in num1
	; -----------------------------

	call clearbuffer	; clear buffer so that previous contents are discarded

	; -- take input second number --
	mov dx, offset msg2
	call printstr

	call readhex
	mov num2, ebx	; store in num2
	;-------------------------------


	; --- print addition of numbers ----
	mov dx, offset msg3
	call printstr

	mov eax, num1
	add eax, num2
	call printhex
	;-----------------------------------

	; --- print subtraction of numbers ----
	mov dx, offset msg4
	call printstr

	mov eax, num1
	sub eax, num2
	call printhex
	;--------------------------------------
	
	; --- print multiplication of numbers ----
	mov dx, offset msg5
	call printstr

	mov eax, num1
	mul num2	; 64 bit result in EDX-EAX
	push eax	; save eax

	mov eax, edx
	call printhex	; print EDX

	pop eax		; restore eax
	call printhex	; print EAX
	;--------------------------------------
	
	; --- print division of numbers ----
	mov dx, offset msg6
	call printstr

	mov edx, 0
	mov eax, num1	; 64 bit contents of EDX-EAX are divided by 32 bit operand specified by div instruction
	div num2
	push edx

	mov dx, offset msg7
	call printstr

	call printhex ; 32 bit quotient is in eax, print it

	mov dx, offset msg8
	call printstr

	pop edx
	mov eax, edx	; 32 bit remainder is in edx
	call printhex
	;--------------------------------------
	

	EXIT:
		mov ax, 4c00h
		int 21h
main endp
end main
