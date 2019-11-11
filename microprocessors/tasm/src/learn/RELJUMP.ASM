.model small
.code

main proc
        jmp $+6
        mov ax, 1234h
        mov ax, 1111h
        mov ax, 1233h
        mov ax, 4c00h
        int 21h
main endp
end main

