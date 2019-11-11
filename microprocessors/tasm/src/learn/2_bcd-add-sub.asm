.model small
.386
.stack 100h

include io.inc

.data
	num1 dd 01000009h
	num2 dd 09999998h
	msg0 db 13, 10, '**** 32 bit BCD Addition and Subtraction ****$'
	msg1 db 13, 10, 'Enter first  8 digit BCD number: $'
	msg2 db 13, 10, 'Enter second 8 digit BCD number: $'
	msg3 db 13, 10, 'BCD Addition    (num1 + num2)  : $'
	msg4 db 13, 10, 'BCD Subtraction (num2 - num1)  : $'

.code

main proc

	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	call printstr

	; --input first number--
	mov dx, offset msg1
	call printstr

	call readhex
	mov num1, ebx
	;-----------------------	


	; --input second number--
	mov dx, offset msg2
	call printstr

	call readhex
	mov num2, ebx
	;-----------------------	

	mov ecx, 0
	mov edx, num1
	mov ebx, num2

	;------------------------- 32 bit BCD addition -------------------

	; because the DAA instruction functions only with the Al register, this addition must occur 8 bits at a time

	; first add bl and dl
	mov al, bl
	add al, dl
	daa
	mov cl, al

	; now add bh and dh
	mov al, bh
	adc al, dh
	daa
	mov ch, al


	pushf	; push flags since rol instruction affects the carry flag

	; now we need to add the high word, so we rotate the numbers by 16 bits to get high word values into low word
	rol edx, 16
	rol ebx, 16
	rol ecx, 16
	
	popf

	; again add bl and dl
	mov al, bl
	adc al, dl
	daa
	mov cl, al

	; now add bh and dh
	mov al, bh
	adc al, dh
	daa
	mov ch, al

	ror ecx, 16

	mov dx, offset msg3
	call printstr

	mov eax, ecx
	call printhex
	;--------------------------------------------------------------------


	;------------------------- 32 bit BCD subtraction -------------------
	mov edx, num1
	mov ebx, num2

	
	; first subtract dl from bl
	mov al, bl
	sub al, dl
	das
	mov cl, al

	; now subtract dh from bh
	mov al, bh
	sbb al, dh
	das
	mov ch, al

	pushf
	; now we need to subtract the high word, so we rotate the numbers by 16 bits to get high word values into low word
	rol edx, 16
	rol ebx, 16
	rol ecx, 16
	popf

	; again subtract dl from bl
	mov al, bl
	sbb al, dl
	das
	mov cl, al

	; now subtract dh from bh
	mov al, bh
	sbb al, dh
	das
	mov ch, al

	ror ecx, 16

	mov dx, offset msg4
	call printstr

	mov eax, ecx
	call printhex

	;--------------------------------------------------------------------

	mov ax, 4c00h
	int 21h

main endp
end main

