.model small
.stack 100h

include io.inc

.data
	arr		dw 11, 2, 33, 48, 51
	key 		dw ?
	arrmsg		db 13, 10, 'The array is: $'
	msg		db 13, 10, 'Enter element to search: $'
	search		db 13, 10, 'Searching for: $'
	foundmsg	db 13, 10, 'Found at index $'
	notfoundmsg 	db 13, 10, 'not found$'
	crlf		db 13, 10, '$'
	commaspace	db ', $'
.code

printarr proc
	mov si, 0
	mov cx, 5
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
	ret
printarr endp

main PROC
	mov ax, @data
	mov ds, ax

	mov dx, offset arrmsg
	call printstr
	call printarr

	;----take input of search key --
	mov dx, offset msg
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
	 
	mov si, 0	; set index to 0
	mov cx, 5	; 5 elements in array
	mov ax, key	; needed since read changed al 
	SEARCHLOOP:
		mov bx, arr[si]	; copy array element to bx
		cmp bx, ax
		je FOUND
		inc si
		inc si
		loop SEARCHLOOP

	NOTFOUND:
		mov dx, offset notfoundmsg
		call printstr
		jmp EXIT
	FOUND:
		mov dx, offset foundmsg
		call printstr
		mov ah, 02h
		shr si, 1
		mov dx, si
		add dl, 30h
		int 21h

	EXIT:	mov ax, 4c00h
		int 21h
main endp
end main
