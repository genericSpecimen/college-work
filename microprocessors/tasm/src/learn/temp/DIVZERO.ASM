.model tiny

.code

main proc
        mov ax, 4
        mov bx, 0
        div bx
        mov ax, 4c00h
        int 21h
main endp
end main

