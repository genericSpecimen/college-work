.model tiny
.LISTALL
.code

.startup

main1:  mov ah, 06h
        mov dl, 0ffh
        int 21h

        je main1
        cmp al, 3
        je main2

        .IF al >= 'a' && al <= 'z'
                sub al, 20h
        .ENDIF

        mov dl, al
        int 21h

        jmp main1
main2:  mov ax, 4c00h
        int 21h
end

