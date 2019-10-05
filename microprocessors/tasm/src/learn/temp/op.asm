.model small
.stack 100h

include io.inc

.code
main proc
	mov ax, @data
	mov ds, ax

	mov ax, 100
	call itos
	mov dx, offset bufferout
	call printstr

	mov ax, 4c00h
	int 21h
main endp
end main
