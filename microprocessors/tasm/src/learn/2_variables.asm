.MODEL SMALL
.STACK 200H

.DATA
	STRING DB "I'm a string$"

.CODE

START:
	; WRITE STRING TO STANDARD OUTPUT
	; AH = 09h
	; DS:DX -> '$'-terminated string
	; DS = segment of the text
	; DX = offset in the segment
	MOV AX, SEG STRING
	MOV DS, AX
	MOV DX, OFFSET STRING
	MOV AH, 09H
	INT 21H

	MOV AH, 4CH
	MOV AL, 00H
	INT 21H
END START
