global main
section .data
m db 53
section .text

main:

mov al,[m]
add al,'0'
mov [m],al

mov rax, 1
mov rdi, 1
mov rsi, m
mov rdx, 1
syscall


mov rax, 60
xor rdi, rdi
syscall