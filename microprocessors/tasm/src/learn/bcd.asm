.model small
.386
.stack 100h

include io.inc

.data
	num1 db ?

.code

main proc

	mov ax, @data
	mov ds, ax

	; BCD data
	; numbers always appear in packed BCD form, stored as two BCD digits per byte
	; adjustment instructions function only with the AL register after BCD addition and subtraction

	; DX and BX each contain 4 digit packed BCD numbers
	; we want to add the BCD numbers in DX and BX, and store the result in CX

	mov dx, 1234h
	mov bx, 3099h

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

	mov eax, ecx
	call printhex

	mov dx, 1234h
	mov bx, 3099h

	; DAS (after subtraction)
	mov al, bl
	sub al, dl
	das
	mov cl, al

	mov al, bh
	sbb al, dh
	das
	mov ch, al


	mov eax, ecx
	call printhex

	mov ax, 4c00h
	int 21h

main endp
end main

