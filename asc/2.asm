global main
section .data
m db ''
section .text

main:

mov rax, 0
mov rdi, 0
mov rsi, m
mov rdx, 1
syscall


mov rax, 1
mov rdi, 1
mov rsi, m
mov rdx, 1
syscall


mov rax, 60
xor rdi, rdi
syscall