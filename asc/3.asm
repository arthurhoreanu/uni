global main
section .data
n1 db 1
n2 db 2

c db '5'
e db 10
section .text

main:

mov rax,0
mov rdi,0
mov rsi,n1
mov rdx,1
syscall

mov al,[n1]
sub al,'0'
mov [n1],al

mov rax,0
mov rdi,0
mov rsi,n2
mov rdx,1
syscall

mov al,[n2]
sub al,'0'
mov [n2],al

;suma n1+n2->c
xor rax,rax
mov al,[n1]
mov ah,[n2]
add al, ah
add al,'0'
mov [c],al

mov rax,1
mov rdi,1
mov rsi,c
mov rdx,1
syscall

mov rax,1
mov rdi,1
mov rsi,e 
mov rdx,1
syscall

mov rax,60
mov rdi,0
syscall