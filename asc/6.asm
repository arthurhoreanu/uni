global main
 
section .data
    a db 1000 dup(0)
    i db 0
    x db 0
    n db 3
 
section .text
 
citnr:
    mov rax, 0
    mov rdi, 0
    mov rsi, x
    mov rdx, 1
    syscall
 
    mov al, [x]
    sub al, '0'
   
    xor rcx, rcx
    mov cl, [i]
    mov [a + ecx], al
 
    ret
 
main:
    mov rax, 0
    mov rdi, 0
    mov rsi, n
    mov rdx, 1
    syscall
 
    mov al, [n]
    sub al, '0'
    mov [n], al
 
    mov r8b, [n]
    loop1:
        call citnr
        mov al, [i]
        inc al
        mov [i], al
        dec r8b
        cmp r8b, 0
        ja loop1
 
    mov rax, 60
    xor rdi, rdi
    syscall