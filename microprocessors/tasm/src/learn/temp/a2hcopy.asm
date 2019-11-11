.model tiny

.data
	hex	db ?
	badhex	db 13, 10, 'Invalid hexadecimal character!$'
.code

main proc
	mov ax, @data	
	mov ds, ax


	mov ah, 01h
	int 21h
	; al = entered character

	cmp al, 'a'
	jb UPPER	; if al < 'a', check for uppercase letters A-F
	cmp al, 'f'
	ja INVALID	; if al > 'f', exit, since 'f' is the last possible hex character in ASCII table
	sub al, 57h	; convert a-f to hex
	jmp EXIT

UPPER:
	cmp al, 'A'
	jb NUMBER	; if al < 'A', check for numbers
	cmp al, 'F'
	ja INVALID	; if al > 'F' and we are at this point, then  'F' < al < 'a', which is an invalid hex character so we exit
	sub al, 37h	; convert A-F to hex
	jmp EXIT
NUMBER:
	cmp al, '0'
	jb INVALID	; if al < '0'
	cmp al, '9'
	ja INVALID
	sub al, 30h	; ASCII('0') = 0x30
	jmp EXIT

INVALID:
	mov dx, offset badhex
	mov ah, 09h
	int 21h
EXIT:	mov ax, 4c00h
	int 21h

main endp
end main

