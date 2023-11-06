global main

section .data
section .text

main:
xor rax,rax
mov ah,0
mov al,255
add al,2
adc ah,0

mov rax,60
mov rdi,0
syscall