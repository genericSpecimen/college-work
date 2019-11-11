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
	sub al, 20h	; convert lowercase to uppercase: ASCII('a') = 0x61, ASCII('A') = 0x41

UPPER:
	cmp al, 'A'
	jb NUMBER	; if al < 'A', check for numbers
	cmp al, 'F'
	ja INVALID	; if al > 'F' and we are at this point, then  'F' < al < 'a', which is an invalid hex character so we exit
	sub al, 7h	; ASCII('A') = 41h, we need to extract value 'A', so we subtract 7h (41h - 7h = 3A h)

NUMBER:
	cmp al, '0'
	jb INVALID	; if al < '0'
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

