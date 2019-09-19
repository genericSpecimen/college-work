; uses printf function from C
; gcc will be used to link instead of ld:	gcc -m32 ex10.o
; C defines _start and expects a program to have main label

global main	; export main label to tell gcc where main function is
extern printf	; since we need to use printf, we need to tell NASM that this is an external symbol

section .data
	msg db "Testing %i...", 0x0a, 0x00	; format string followed by newline (0x0a) and null terminator (end of string)

main:
	; --prologue--
	push ebp
	mov ebp, esp
	; ------------

	; printf(msg, 123) : args passed in reverse order, since stack is used
	push 123
	push msg
	call printf

	mov eax, 0
	; --epilogue--
	mov esp, ebp
	pop ebp
	ret
	; ------------

