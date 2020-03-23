%macro print 4  ; defining macro
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

section .data   ;initializing variables
    msg_1 db "Welcome ",10,13
    msg_1_len equ $-msg_1
    msg_2 db "Nikhil",10,13
    msg_2_len equ $-msg_2
    newLine db 10,13

    

section .bss    ; only defining no intialisation
    cnt resq 1 ; reserve quad word

section .text   ;driver code
global main
main : 
    print 1,1,msg_1,msg_1_len
    print 1,1,newLine,1
    print 1,1,msg_2,msg_2_len

    mov rax,60
    mov rbx,0