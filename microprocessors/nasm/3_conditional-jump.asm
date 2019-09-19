global _start

section .text
_start:
	mov eax, 1	; sys_exit
	mov ebx, 42	; exit code
	mov ecx, 99
	;mov ecx, 101
	cmp ecx, 100	; compare ecx to 100
	jl skip		; (conditional) jump if less than (to skip label)
	mov ebx, 13	; won't be executed

skip:
	int 0x80

