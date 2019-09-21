.model small
.stack 100h

.data
	arr		db 1, 2, 3, 4, 5
	key 		db ?
	msg		db 'Enter element to search: $'
	foundmsg	db 13, 10, 'Found$'
	notfoundmsg 	db 13, 10, 'not found$'
	search		db 13, 10, 'Searching for: $'
.code

; procedure to print an ASCII value
printnum proc

	push bp
	mov bp, sp

	mov dl, [bp+4]
	add dl, 30h

	; WARNING: read returns some value in AL
	;AH = 02h
	;DL = character to write
	;Return: AL = last character output (despite the official docs which state nothing is returned) (at least DOS 2.1-7.0)

	mov ah, 02h
	int 21h
	
	mov sp, bp
	pop bp
	ret

printnum endp


; procedure to print a string
printstring proc

	push bp
	mov bp, sp

	mov dx, [bp+4]
	mov ah, 09h
	int 21h

	mov sp, bp
	pop bp
	ret

printstring endp

main PROC
	mov ax, @data
	mov ds, ax

	;----print msg-------
	push offset msg
	call printstring
	;--------------------

	;----read character from stdin--
	mov ah, 01h	; read search key
	int 21h
	;-------------------------------

	sub al, 30h	; subtract '0' (30h) to get numerical value
	mov key, al

	;----- print "searching for: key"---
	push offset search
	call printstring

	push ax
	call printnum
	;----------------------------------
	 
	xor di, di	; set index to 0
	mov cx, 5	; 5 elements in array
	mov al, key	; needed since read changed al 
	SEARCHLOOP:
		mov bl, arr[di]	; copy array element to bl
		cmp bl, al
		je FOUND
		inc di
		loop SEARCHLOOP

	NOTFOUND:
		push offset notfoundmsg
		call printstring
		jmp EXIT
	FOUND:
		push offset foundmsg
		call printstring

	EXIT:	mov ax, 4c00h
		int 21h
main endp
end main
