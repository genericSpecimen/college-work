#!/bin/bash
PROG=$1

nasm -f elf32 "$PROG".asm -o "$PROG".o
ld -m elf_i386 "$PROG".o -o "$PROG"
./"$PROG"

rm "$PROG".o "$PROG"
