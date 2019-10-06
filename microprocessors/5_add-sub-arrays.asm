.model small
.stack 100h

include io.inc

.data
	ARRSIZE equ 10
	arr1	dw 10, 20, 30, 78, 90, 12, 13, 10, 9, 60
	arr2	dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	arr3	dw 10 dup(?)	; stores the addition
	arr4	dw 10 dup(?)	; stores the subtraction
	msg0	db 13, 10, '**** Addition and Subtraction of two arrays **** $'
	msg1	db 13, 10, 'First array: $'
	msg2	db 13, 10, 'Second array: $'
	msg3	db 13, 10, 'Addition: $'
	msg4	db 13, 10, 'Subtraction: $'
	commaspace db ', $'
.code

printarr proc
	; requires bx : starting address (offset) of array
	; -- save registers --
	push si
	push cx
	push ax
	push dx
	;---------------------
	
	mov si, 0
	mov cx, ARRSIZE
	printloop:

		mov ax, [bx+si]
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

addarrays proc
	; -- save registers ---
	push ax
	push cx
	push si
	; ---------------------
	; adds arr1 and arr2 and stores it in arr3
	mov cx, ARRSIZE
	shl cx, 1	; since word sized data
	mov si, 0
	ADDLOOP:
		mov ax, arr1[si]
		add ax, arr2[si]
		mov arr3[si], ax
		inc si
		inc si
		loop ADDLOOP
	;-- restore registers --
	pop si
	pop cx
	pop ax
	;-----------------------
	ret
addarrays endp

subarrays proc
	; -- save registers ---
	push ax
	push cx
	push si
	; ---------------------
	; subtracts arr2 from arr1  and stores it in arr4
	mov cx, ARRSIZE
	shl cx, 1	; since word sized data
	mov si, 0
	SUBLOOP:
		mov ax, arr1[si]
		sub ax, arr2[si]
		mov arr4[si], ax
		inc si
		inc si
		loop SUBLOOP
	;-- restore registers --
	pop si
	pop cx
	pop ax
	;-----------------------
	ret
subarrays endp


main proc

	mov ax, @data
	mov ds, ax

	mov dx, offset msg0
	call printstr

	mov dx, offset msg1
	call printstr

	mov bx, offset arr1
	call printarr

	mov dx, offset msg2
	call printstr

	mov bx, offset arr2
	call printarr

	call addarrays

	mov dx, offset msg3
	call printstr

	mov bx, offset arr3
	call printarr

	call subarrays

	mov dx, offset msg4
	call printstr

	mov bx, offset arr4
	call printarr

	mov ax, 4c00h
	int 21h
main endp
end main
