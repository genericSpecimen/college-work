.model small
.stack 200h
.code

START:
	mov ah, 2	; which function to do, 2 specifies DISPLAY OUTPUT FUNCTION
        mov dl, 69	; what to display, 69 in ASCII is E
	int 21h		; use interrupt number 21h

	;---EXIT- TERMINATE with return code, required for proper termination---
	mov ah, 4ch 	; www.ctyme.com/intr/rb-2974.htm
	mov al, 00h	; return code 00h
	int 21h
	;-------------------------------------
END START

