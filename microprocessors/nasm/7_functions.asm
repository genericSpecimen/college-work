global _start

section .text
_start:
	call func
	mov eax, 1
	int 0x80

func:
	mov ebx, 42
	; or just ret
	; pop eax
	; jmp eax

	ret
