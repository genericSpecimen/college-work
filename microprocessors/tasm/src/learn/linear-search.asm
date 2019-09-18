.model small
.stack 100h

.data
	msg		db 'Enter element to search: $'
	arr		db 1, 2, 3, 4, 5
	foundmsg	db 13, 10, 'Found$'
	notfoundmsg 	db 13, 10, 'not found$'
	key 		db ?
	scanned		db 13, 10, 'Scanned: $'
.code

main PROC
	mov ax, seg msg
	mov ds, ax
	
	; print msg
	mov dx, offset msg
	mov ah, 09h
	int 21h

	; read character (into al)
	mov ah, 01h
	int 21h

	; print character read
	; mov ah, 02h
	; mov dl, al
	; int 21h

	mov key, al
	mov ah, 02h
	mov dl, key
	int 21h
	; mov bl, arr
	xor di, di ; set index to 0
	SEARCHLOOP:
		mov al, arr[di]

		mov dx, offset scanned
		mov ah, 09h
		int 21h
		
		mov ah, 02h
		mov dl, al
		int 21h

		cmp al, key
		je FOUND
		inc di
		cmp di, 5
		jz NOTFOUND
		loop SEARCHLOOP

	FOUND:
		mov dx, offset foundmsg
		mov ah, 09h
		int 21h

	NOTFOUND:
		mov dx, offset notfoundmsg
		mov ah, 09h
		int 21h

	; exit with return code 0
	mov ax, 4c00h
	int 21h
main endp
end main
