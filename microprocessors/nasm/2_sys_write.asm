global _start

section .data
	msg db "Hello world!", 0x0a	; 0x0a = 10 = code for newline
	len equ $ - msg

section .text
_start:
	mov eax, 4	; sys_write system call
	mov ebx, 1	; stdout file descriptor
	mov ecx, msg	; bytes to write
	mov edx, len	; number of bytes to write
	int 0x80	; perform system call

	mov eax, 1	; sys_exit system call
	mov ebx, 0	; exit code 0
	int 0x80	; perform system call
