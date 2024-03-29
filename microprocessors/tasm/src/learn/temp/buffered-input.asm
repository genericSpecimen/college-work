.model small
.stack 100h

.data
	crlf	db 13, 10, '$'
	string	db 6	; max number of characters allowed
		db ?	; number of characters entered by user
		db 6 dup (?)	; characters entered by user
		db '$'
	num	dw ?
	msg	db 'Value of bx: $'
.code

; ------------------------------------stoi-------------------------------------
stoi proc
; converts string to integer and puts it in bx

; si points to the start of string (buffer input)

; Format of DOS input buffer:
; Offset  Size    Description     (Table 01344)
; 00h    BYTE    maximum characters buffer can hold
; 01h    BYTE    (call) number of chars from last input which may be recalled
; (ret) number of characters actually read, excluding CR
; 02h  N BYTEs   actual characters read, including the final carriage return

	inc si
	mov cl, [si]	; num of chars entered
	mov ch, 0	; make cx == cl
	add si, cx	; make si point to LSD

	mov bx, 0	; stores the result
	mov bp, 1	; multiply by (1, 10, 100, ...)
	CONVERT_CHAR:
		mov al, [si]	; character to process
		sub al, 30h	; al - '0'
		mov ah, 0	; make ax == al
		mul bp		; ax = ax*bp
		add bx, ax	; add result

		mov ax, bp
		mov bp, 10
		mul bp		; multiply current weight by 10
		mov bp, ax	; new weight

		dec si		; next digit
		loop CONVERT_CHAR
	ret
stoi endp
; -----------------------------------------------------------------------------


; ------------------------------------writedollars-----------------------------
writedollars proc
	mov si, offset string
	mov cx, 8
	dollars:
		mov bl, '$'
		mov [si],  bl
		inc si
		loop dollars
	ret
writedollars endp
; -----------------------------------------------------------------------------


; -------------------------------------itos------------------------------------
itos proc
; convert integer in ax to string
	call writedollars
	mov cx, 0
	pushcycle1: ; push numbers onto stack
		mov dx, 0
		cmp ax, 0
		je retrieve

		mov bx, 10
		div bx
		push dx
		inc cx
		jmp pushcycle1
		
	retrieve:
		mov si, offset string
	popcycle1:	; pop and output
		cmp cx, 0
		je exitfunc1

		pop dx
		add dl, 30h
		mov [si], dl
		inc si
		loop popcycle1

	exitfunc1:
		mov ah, 02h
		mov dl, 0
		int 21h
		ret
itos endp
; -----------------------------------------------------------------------------


printcrlf proc
	mov ah, 09h
	mov dx, offset crlf
	int 21h
	ret
printcrlf endp

printstr proc
	; requires dx : offset of string
	mov ah, 09h
	int 21h
	ret
printstr endp

main proc
	mov ax, @data
	mov ds, ax

	; buffered input
	mov ah, 0ah
	mov dx, offset string
	int 21h

	call printcrlf
	
	; convert string to number, result is in bx
	mov si, offset string
	call stoi
	
	; convert number in ax to string
	mov ax, bx
	call itos

	mov dx, offset msg
	call printstr

	mov dx, offset string
	call printstr

	mov ax, 4c00h
	int 21h
main endp
end main

