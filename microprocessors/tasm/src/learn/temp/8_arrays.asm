.model small
.stack 100h

.data

	array	db 	1, 2, 3, 4, 5
	sum	db	0
	msg	db	13, 10, "Sum of elements of array: $"
.code

main PROC

	mov ax, @data
	mov ds, ax

	xor al, al	; same as mov ax, 0
	xor cx, cx	; initialise counter to 0
	mov bx, offset array

L1:
	add al, [bx]
	inc cx
	cmp cx, 5
	je L2
	inc bx
	jmp L1
L2:
	mov sum, al
	add sum, 100d

	mov ah, 09h
	mov dx, offset msg
	int 21h

	mov ah, 02h
	mov dl, sum
	int 21h

	mov ax, 4c00h
	int 21h
main ENDP
END main
