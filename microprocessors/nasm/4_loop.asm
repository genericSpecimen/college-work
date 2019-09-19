global _start

section .text
_start:
	mov ebx, 1
	mov ecx, 4	; number of iterations

looplabel:
	add ebx, ebx	; ebx += ebx
	dec ecx		; ecx--
	cmp ecx, 0	; compare ecx with 0
	jg looplabel	; jump if greater to label


	mov eax, 1	; sys_exit system call
	int 0x80

