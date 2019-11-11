.model tiny
.code

main proc
        mov al, 48h
        mov ah, 0
        aam     ; convert to BCD
        add ax, 3030h   ; convert to ASCII
        push ax
        mov dl, ah
        mov ah, 2
        int 21h
        pop ax
        mov dl, al
        mov ah, 2
        int 21h

main endp
end main
