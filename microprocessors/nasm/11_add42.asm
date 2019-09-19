global add42 ; make add42 accessible to linker

add42:
	; prologue
	push ebp
	mov ebp, esp

	; add 42
	mov eax, [esp+8]
	add eax, 42

	; epilogue
	mov esp, ebp
	pop ebp
	ret

