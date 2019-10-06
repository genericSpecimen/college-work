.model small
.stack 100h

include io.inc

.data
	ARRSIZE		equ 10
	arr		dw 11, 2, 33, 48, 51, 100, 267, 89, 112, 69
	key 		dw ?
	msg0		db 13, 10, '**** Linear search **** $'
	arrmsg		db 13, 10, 'The array is: $'
	msg1		db 13, 10, 'Enter element to search: $'
	search		db 13, 10, '=> Searching for: $'
	foundmsg	db 13, 10, '=> Found at index $'
	notfoundmsg 	db 13, 10, '=> Not found$'
	crlf		db 13, 10, '$'
	commaspace	db ', $'

.code

printarr proc
	; -- save registers --
	push si
	push cx
	push ax
	push dx
	;---------------------
	
	mov si, 0
	mov cx, ARRSIZE
	printloop:

		mov ax, arr[si]
		call itos
		mov dx, offset bufferout
		call printstr

		mov dx, offset commaspace
		call printstr

		inc si
		inc si
		loop printloop
	; -- restore registers --
	pop dx
	pop ax
	pop cx
	pop si
	; -----------------------
	ret
printarr endp

linearsearch proc 
	; --- save registers ---
	push si
	push cx
	push ax
	push bx
	push dx
	; ----------------------


	mov si, 0	; starting index of search is 0
	mov cx, ARRSIZE	; number of elements in array
	mov ax, key	; store key in ax 
	LSLOOP:
		mov bx, arr[si]	; copy array element to bx
		cmp bx, ax
		je LSFOUND
		inc si
		inc si
		loop LSLOOP

	LSNOTFOUND:
		mov dx, offset notfoundmsg
		call printstr
		jmp LSEXIT
	LSFOUND:
		mov dx, offset foundmsg
		call printstr
		mov ah, 02h
		shr si, 1
		mov dx, si
		add dl, 30h
		int 21h

	LSEXIT:
	; --- restore contents of registers ---
	pop dx
	pop bx
	pop ax
	pop cx
	pop si
	; -------------------------------------
	ret
linearsearch endp

main PROC
	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	call printstr

	mov dx, offset arrmsg
	call printstr
	call printarr

	;----take input of search key --
	mov dx, offset msg1
	call printstr

	mov ah, 0ah
	mov dx, offset bufferin
	int 21h

	call stoi	; convert input to integer (which gets stored in bx)
	;-------------------------------

	mov key, bx	; store in key

	;----- print "searching for: key"---
	mov dx, offset search
	call printstr

	mov ax, key
	call itos	; convert integer to string (which gets stored in bufferout)

	mov dx, offset bufferout
	call printstr
	;----------------------------------
	
	call linearsearch

	EXIT:
		mov ax, 4c00h
		int 21h
main endp
end main
