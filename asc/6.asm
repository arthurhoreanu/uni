global main

section .data
 a db 1000 dup(0)
 i db 3

section .text

main:
 mov rax,0
 mov rdi,0
 mov rsi,i
 mov rdx,1
 syscall

 mov al,[i]
 sub al,'0'
 mov [i],al

 mov [a+1],

 mov cl,33
 mov [a+3],cl
 mov bl,[i]
 mov al,[ebx+a]
 
 mov rax,60
 xor rdi,rdi
 syscall