global _start

section .text
_start:
	push 21		; values are passed using the stack
	call times2
	mov ebx, eax	; return value is in eax since we perform computation in eax in times2 function; acts as the exit code in this example
	mov eax, 1	; sys_exit
	int 0x80

times2:
	;----function prologue-----
	push ebp	; save current ebp value
	mov ebp, esp	; store current esp value (top of stack) in ebp
	mov eax, [esp+8]; +8 since 2 items (64 bits = 8 bytes) have been pushed onto stack (call and push ebp)
	add eax, eax

	;----function epilogue-----
	mov esp, ebp	; restore esp value
	pop ebp		; restore ebp value
	ret
