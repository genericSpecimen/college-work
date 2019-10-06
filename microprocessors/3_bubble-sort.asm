.model small
.stack 100h

include io.inc 

.data
	msg		db 13, 10, '**** Sorting an array using Bubble Sort **** $'
	ARRSIZE 	equ 10
	arr		dw 23, 67, 1, 2, 90, 11, 21, 89, 100, 0
	original	db 13, 10, 'Original array: $'
	sorted		db 13, 10, 'Sorted array: $'
	commaspace	db ', $'

	outerdbg	db 13, 10, 'Outer loop counter: $'
	innerdbg	db 13, 10, '   Inner loop counter: $'
	cmpdbg1		db ' Compared $'
	cmpdbg2		db ' and $'

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

sort proc
	; -- save registers --
	push ax
	push bx
	push cx
	push dx
	push di
	push si
	
	; --------------------
	; TODO
	mov cx, 0	; counter for outer loop
	mov si, ARRSIZE
	sub si, 2
	shl si, 1	; max index pair to compare == (ARRSIZE-2)*2 (since data is word sized)
	outerloop:
		;-----------debug-------------
		;mov dx, offset outerdbg
		;call printstr
		;mov ax, cx
		;call itos
		;mov dx, offset bufferout
		;call printstr
		;------------------------
		
		cmp cx, ARRSIZE	; if counter == size
		je exit
		mov di, 0	; counter for inner loop

		innerloop:
			;---------debug--------------
			;mov dx, offset innerdbg
			;call printstr
			;mov ax, di
			;call itos
			;mov dx, offset bufferout
			;call printstr
			;-----------------------

			cmp di, si
			jg innerdone

			;---------debug--------------
			;mov dx, offset cmpdbg1
			;call printstr
			;-----------------------
			mov ax, arr[di]
			;call itos
			;mov dx, offset bufferout
			;call printstr

			;mov dx, offset cmpdbg2
			;call printstr
			mov bx, arr[di+2]
			;call itos
			;mov dx, offset bufferout
			;call printstr
			cmp ax, bx
			jle NOSWAP
			xchg ax, bx
			mov arr[di], ax
			mov arr[di+2], bx
			NOSWAP:
			
			add di, 2
			jmp innerloop
		innerdone:
			inc cx
			jmp outerloop
			
	exit:
		; -- restore registers --
		pop si
		pop di
		pop dx
		pop cx
		pop bx
		pop ax
		; -----------------------
		ret 
sort endp

main proc
	mov ax, @data
	mov ds, ax

	mov dx, offset msg
	call printstr

	; -- print original array ---
	mov dx, offset original
	call printstr
	call printarr
	; ---------------------------

	call sort

	; -- print sorted array ---
	mov dx, offset sorted
	call printstr
	call printarr
	; ---------------------------

	mov ax, 4c00h
	int 21h
main endp
end main
