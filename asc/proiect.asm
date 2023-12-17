global main
section .data
prompt db 'Introduceți un număr între 0 și 5: ', 0
n db 0
f db 0
c db 0
section .text

main:
mov rax, 1
mov rdi, 1 
mov rsi, prompt
mov rdx, 40
syscall

mov rax, 0
mov rdi, 0
mov rsi, n
mov rdx, 1
syscall

mov rax, 1
mov rbx, [n]
sub rbx, '0'

factorial:
cmp rbx, 0
je afisare
imul rax, rbx
dec rbx
ja factorial

afisare:
mov [f], rax
do:
xor rax, rax
mov al, [f]
mov bl, 10
div bl
add ah, '0'
mov [c], ah
mov [f], al
mov rax, 1
mov rax, 1
mov rdi, 1
mov rsi, c
mov rdx, 1
syscall
mov bl, [f]
cmp bl,0
ja do

mov rax, 60
mov rdi, 0
syscall