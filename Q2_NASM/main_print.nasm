; main_print.nasm

section .data
    msg db "Este trabalho foi realizado por Gabriel Velasquez e Thaynara Nascimento!", 10
    len equ $ - msg

section .text
    global main

main:
    ; write(1, msg, len)  
    mov     rax, 1       
    mov     rdi, 1      
    mov     rsi, msg    
    mov     rdx, len     
    syscall

    mov     eax, 0     
    ret
