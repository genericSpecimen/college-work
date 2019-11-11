.model small

.code

testproc proc prolog near uses ax
        mov ax, 1000h
        ret
testproc endp

main proc

       mov ax, 1234h
       call testproc

main endp
end main

