.model small
.386
.stack 100h

.code

main proc

	mov ax, @data
	mov ds, ax
	mov cx, 32

	mov ebx, 10h
PRINT:
	shl ebx, 1	; carry gets highest bit

	mov dl, 30h
	adc dl, 0	; imm data = 0, only carry is added

	mov ah, 02h
	int 21h
	loop PRINT

	mov ax, 4c00h
	int 21h
main endp
end main
