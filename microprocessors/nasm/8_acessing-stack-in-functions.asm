global _start

section .text
_start:
	call func
	mov eax, 1	; sys_exit
	mov ebx, 0	; exit code 0
	int 0x80

func:
	; -----------prologue of function--------------
	push ebp	; save current ebp value onto stack
	mov ebp, esp	; save current stack state (esp) into ebp
	sub esp, 2	; allocate 2 bytes and store 'Hi'
	; ---------------------------------------------

	mov [esp], byte 'H'
	mov [esp+1], byte 'i'

	mov eax, 4	; sys_write
	mov ebx, 1	; stdout file descriptor
	mov ecx, esp	; bytes to write
	mov edx, 2	; number of bytes to write
	int 0x80

	; -----------epilogue of function--------------
	mov esp, ebp	; restore previous stack state
	pop ebp		; restore value of ebp
	ret
	; ---------------------------------------------

