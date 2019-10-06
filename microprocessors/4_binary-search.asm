.model small
.stack 100h

include io.inc

.data
	ARRSIZE		equ 10
	arr		dw 2, 11, 33, 48, 51, 69, 89, 100, 112, 267
	key 		dw ?
	msg0		db 13, 10, '**** Binary Search ****$'
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


binarysearch proc

	; -- save registers --
	push ax
	push bx
	push cx
	push dx
	push si
	; --------------------

	mov ax, key	; key to be searched
	mov bx, 0	; low index
	; high index = (ARRSIZE - 1) * 2
	mov cx, ARRSIZE
	dec cx
	shl cx, 1

	;-------------------------------------
	BSLOOP:
		cmp bx, cx	; while (low <= high)
		jg BSNOTFOUND
		
		; ----- mid (si)  = (low+high)/2 -----
		mov si, bx
		add si, cx
		shr si, 1

		; if mid is odd, then add 1 to it, since array indices must be multiples of 2
		mov dx, si	; save si first
		and si, 1	; and with 1
		jz EVENNUM		; no need to add 1 if already even
		add dx, 1
		EVENNUM:
		mov si, dx	; restore si
		; ------------------------------------

		cmp arr[si], ax; if (arr[mid] == key)
		je BSFOUND
		jl HIGHER	; else if (arr[mid] < key) low = mid+1
		jmp LOWER	; else high = mid-1
		
			LOWER:
				mov cx, si
				sub cx, 2
				jmp BSLOOP

			HIGHER:
				mov bx, si
				add bx, 2	; word sized data
				jmp BSLOOP

	BSNOTFOUND:
		mov dx, offset notfoundmsg
		call printstr
		jmp BSEXIT
	BSFOUND:
		mov dx, offset foundmsg
		call printstr
		; display index si at which element was found
		mov ah, 02h
		shr si, 1	; internally, indices were multiples of 2, but we must display it as multiples of 1
		mov dx, si
		add dl, 30h
		int 21h

	BSEXIT:	
	; -- restore registers
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	; --------------------
	ret
binarysearch endp

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

	call binarysearch
	
	EXIT:
		mov ax, 4c00h
		int 21h
main endp
end main
