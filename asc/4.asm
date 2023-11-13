global main
section .data
n db 123
c db 0
section .text

main:
;c=n%10
do:
xor rax, rax
mov al,[n]
mov bl,10
div bl ;ax/bl; al=ax/bl, ah=ax%bl
add ah,'0'
mov [c],ah
mov [n],al ;n/=10

mov rax,1
mov rdi,1
mov rsi,c
mov rdx,1
syscall
mov bl,[n]
cmp bl,0
ja do

mov rax,60
mov rdi,0
syscall