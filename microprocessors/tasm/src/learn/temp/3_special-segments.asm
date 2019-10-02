.MODEL SMALL
.STACK 200H

.CODE

START:

	; VIDEO - SET VIDEO MODE
	; AH = 00h
	; AL = desired video mode (http://www.ctyme.com/intr/rb-0069.htm)
	MOV AX, 0003H
	INT 10H

	MOV BX, 0B800H	; For the screen mode we're using, the segment is B800
	MOV ES, BX	; ES: Extra segment, can be used as we wish
	MOV BX, 0	; Offset into the segment (upper left corner of screen)
	MOV AH, 69	; character to be put at ES:BX
	MOV ES:[BX], AH

	MOV AX, 0100H	; wait for user to enter a key
	INT 21H

	MOV AX, 4C00H
	INT 21H

END START
