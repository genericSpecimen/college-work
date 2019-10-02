.model small
.stack 100h

include io.inc 

.data
	arr	dw 12, 23, 3, 10, 1
	arrsize	dw 5
	origin	db 13, 10, 'Original array: $'
	sorted	db 13, 10, 'Sorted array: $'
	comma	db ',$'

	outerdbg db 13, 10, 'Outer loop counter: $'
	innerdbg db 13, 10, '   Inner loop counter: $'
	cmpdbg1 db 13, 10, 'Compared $'
	cmpdbg2 db ' and $'

.code

printarr proc
	mov di, 0
	mov cx, arrsize
	PRINTLOOP:
		mov ax, arr[di]
		call output
		mov dx, offset comma
		call printstr
		add di, 2 ; word
		loop PRINTLOOP
	ret
printarr endp

sort proc
	; TODO
	mov cx, 0	; counter for outer loop

	outerloop:
		;-----------debug-------------
		mov dx, offset outerdbg
		call printstr
		mov ax, cx
		call output
		;------------------------
		
		cmp cx, arrsize	; if counter == size
		je exit
		mov di, 0	; counter for inner loop

		innerloop:
			;---------debug--------------
			;mov dx, offset innerdbg
			;call printstr
			;mov ax, bx
			;call output
			;-----------------------

			cmp di, arrsize
			je innerdone

			mov dx, offset cmpdbg1 
			call printstr
			mov ax, arr[di]
			call output
			mov dx, offset cmpdbg2
			call printstr
			mov ax, arr[di+2]
			call output	
			inc di
			jmp innerloop
		innerdone:
			inc cx
			jmp outerloop
			
	exit:
		ret 
sort endp

main proc
	mov ax, @data
	mov ds, ax

	mov dx, offset origin
	call printstr
	call printarr

	mov dx, offset sorted
	call printstr
	call printarr

	call sort
	mov ax, 4c00h
	int 21h
main endp
end main
