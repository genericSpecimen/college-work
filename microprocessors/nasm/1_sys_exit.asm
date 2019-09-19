global _start ; entry point for our friend, the linker
_start:
	mov eax, 1	; sys_exit
	mov ebx, 42	; exit status
	sub ebx, 29	; subtract 29 from ebx
	int 0x80	; system call interrupt
