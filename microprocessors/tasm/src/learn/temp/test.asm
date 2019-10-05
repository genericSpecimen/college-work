.model small
.stack 100h

.data
	num dw 123

.code

main proc

	mov ax, @data
	mov ds, ax

	mov dx, num
	mov ah, 06h
	int 21h

	mov ax ,4c00h
	int 21h

main endp
end main
