.model tiny
.code

.startup

	in al, 61h
	or al, 3
	out 61h, al
        mov cx, 0FFFFh
	L1:
	loop L1
	in al, 61h
	and al, 0FCh
	out 61h, al

	mov ax, 4c00h
	int 21h
end

