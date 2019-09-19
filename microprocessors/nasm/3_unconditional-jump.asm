global _start

section .text
_start:
	mov eax, 1	; sys_exit
	mov ebx, 42	; exit code
	jmp skip	; (unconditional) jump to skip label
	mov ebx, 13	; won't be executed

skip:
	int 0x80

