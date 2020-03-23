%macro print 4
mov RAX,%1
mov RDI,%2
mov RSI,%3
mov RDX,%4
syscall
%endmacro
  
section .data
choicemsg   db "************ String Operations *************",10,13
            db "1. Non-Overlaping string copy without using string operations",10,13
            db "2. Non-Overlaping string copy using string operations",10,13
            db "3. Overlaping string copy without using string operations",10,13
            db "4. Overlaping string copy using string operations",10,13
            db "5. Exit",10,13
            db " Enter your choice :: "
cmlen equ $-choicemsg
msg1 db "Array elements",10,13
m1len equ $-msg1
arr1 dq 1h,2h,3h,4h
msg2 db "  ",10,13
m2len equ $-msg2
msg3 db "copied array element",10,13
m3len equ $-msg3


section .bss    
buff resq 1
arr2 resq 4
arr3 resq 4
choice resw 1

section .text
global main
main:
          
print 1,1,choicemsg,cmlen
print 0,0,choice,2

cmp byte[choice], 31H 
je choice1
cmp byte[choice], 32H 
je choice2
cmp byte[choice], 33H 
je choice3
cmp byte[choice], 34H 
je choice4
cmp byte[choice], 35H 
je choice5


choice1 :
    print 1,1,msg1,m1len
    mov R9,4
    mov R8, arr1
    up : mov RAX, [R8]
         call display
         print 1,1,msg2,m2len
         add R8,8
         dec R9
         jnz up

         mov R10, arr2
         mov R8, arr1
         mov R9, 4
    upch11:
         mov R11, [R8]
         mov [R10], R11
         add R8, 8
         add R10, 8
         dec R9
         jnz upch11

         print 1,1,msg3,m3len
         mov R10, arr2
         mov R9, 4
    upch12:
         mov RAX, [R10]
         call display
         print 1,1,msg2,m2len
         add R10,8
         dec R9
         jnz upch12
    jmp main

choice2 :
    print 1,1,choice,2
    mov RSI, arr1
    mov RDI, arr3
    mov RCX, 4
    cld
    rep movsq

    print 1,1,msg3,m3len
    mov R10, arr3
    mov R9, 4 
upch21:
    mov RAX, [R10]
    call display
    print 1,1,msg2,m2len
    add R10,8
    dec R9
    jnz upch21
    jmp main

choice3 :
    print 1,1,choice,2
    ;overlaping copy of elements
    mov R8, arr1
    mov R10, arr2
    add R10, 16
    mov R9, 4
upch31:
    mov R11, [R8]
    mov [R10], R11
    add R8, 8
    add R10, 8
    dec R9
    jnz upch31

    print 1,1,msg3,m3len
    mov R10, arr2
    ;add R10, 16
    mov R9, 6 
upch32:
    mov RAX, [R10]
    call display
    print 1,1,msg2,m2len
    add R10,8
    dec R9
    jnz upch32

    jmp main

choice4 :
    print 1,1,choice,2
    mov RSI, arr1
    mov RDI, arr3
    add RDI, 16
    mov RCX, 4
    cld
    rep movsq

    print 1,1,msg3,m3len
    mov R10, arr3
    ;add R10, 16
    mov R9, 6
upch41:
    mov RAX, [R10]
    call display
    print 1,1,msg2,m2len
    add R10,8
    dec R9
    jnz upch41
    jmp main

choice5 : 
    mov RAX,60
    mov RBX,0
    syscall


display:     
          mov RSI,buff
          mov RCX,16

up1 :     rol RAX,4
          mov DL,AL
          AND DL,0fh
          cmp DL,09h
          jle next1
          add DL,07h
next1 : add DL,30h
          mov [RSI],DL
          add RSI,1
          dec RCX
          jnz up1
          print 1,1,buff,16
          ret
