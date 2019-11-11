.model small
.386
.data
	saddr dd ?
	sarea dw 1000h dup(?)
	stop EQU THIS WORD

.code

.startup
	cli
	;mov ax, sp
	mov word ptr saddr, sp

	;mov ax, ss
	mov word ptr saddr+2, ss

	mov ax, ds
	mov ss, ax

	;mov ax, offset stop
	mov sp, offset stop
	sti

	mov ax, ax
	mov ax, ax

	lss sp, saddr

	mov ax, 4c00h
	int 21h
END

