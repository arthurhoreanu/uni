global main
section .data
n db 123
c db '5'
section .text
 
afisc:
mov rax,1
mov rdi,1
mov rsi,c
mov rdx,1
syscall
ret
 
afisnr:
mov al,[n]
mov ah,0
mov r8b,10
div r8b
add ah,'0'
mov [c],ah
call afisc
mov [n],al
cmp al,0
ja afisnr
ret
 
main:
xor rax,rax
call afisnr
 
;exit (0)
mov rax,60
mov rdi,0
syscall