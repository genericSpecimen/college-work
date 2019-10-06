.model small
.stack 100h

.data
	num1 db ?

.code

main proc

	mov ax, @data
	mov ds, ax

	; BCD data
	; numbers always appear in packed BCD form, stored as two BCD digits per byte
	; adjustment instructions function only with the AL register after BCD addition and subtraction

	mov 

main endp
end main
