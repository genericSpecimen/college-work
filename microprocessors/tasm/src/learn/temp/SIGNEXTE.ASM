.model tiny
.386

.code

main proc
        mov ax, 0ff0fh
        movzx ax, al
        mov al, 0ffh
        movsx ax, al
        mov ax, 4c00h
        int 21h

main endp
end main
