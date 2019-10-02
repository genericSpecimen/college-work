.model small
.386
.stack 100h

.data

	num dd 123456

.code
main proc
	mov eax, @data
	mov ds, eax 

	mov eax, num

	mov eax, 4c00h
	int 21h
main endp
end main

