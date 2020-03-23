
%macro print 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

 
 section .data
 
 menu db 10d,13d,"MENU"
      db 10d,"1:HEX to BCD"
      db 10d,"2: BCD to HEX" 
      db 10d,"3:exit"
      db 10d
      db 10d,"enter your choice"
menulen equ $-menu
 
 
 msg_1 db "Enter Hex number",10,0
 m1len equ $-msg_1
 
 msg_2 db "Enter Bcd number",10,0
 m2len equ $-msg_2
       
 section .bss
    choice resw 1
    num resd 1
    numsg_1 resb 5
    result resb 5
    result1 resb 4
    factor resq 5
  
 section .text
 global main
 main:
      
             print 1,1,menu,menulen
             print 00,00,choice,2
             
             cmp byte[choice],"3"
             jae exit
              			
             cmp byte[choice],"1"
             je case1
             
             cmp byte[choice],"2"
             je case2
             
 case1:
 
       print 1,1,msg_1,m1len
       print 0,0,num,4
       
       mov rsi,num
       mov rcx,4
       mov rbx,0
       mov rdx,0
       
    label_1:
        rol rbx,4
        mov al,[rsi]
        cmp al,39h
        jbe label_2
        sub al,07h
       
    label_2:
        sub al,30h
        add rbx,rax
        inc rsi
        dec rcx
        jnz label_1
         
        mov rdi,result+4
        mov rax,rbx
        mov rbx,10
       
    label_3:
        mov rdx,0        
        div rbx
        add dl,30h
        mov[rdi],dl
        dec rdi
        cmp rax,0
        jne label_3
        
        print 1,1,result,5
        
        
        jmp exit
        
    case2:
 
        print 1,1,msg_2,m2len
        print 0,0,numsg_1,5
 
        mov rsi,numsg_1+4
        mov rcx,5
        mov rbx,0
        mov rdx,0
        mov qword[factor],1
       
    label_4:
        mov rax,0
        mov al,[rsi]
        sub al,30h
        mul qword[factor]
        add rbx,rax
        mov rax,10
        mul qword[factor]
        mov qword[factor],rax
        dec rsi
        dec rcx
        jnz label_4  
       
        mov rdi,result1+3
        mov rcx,4
        mov rax,rbx
        mov rbx,16

    label_5:
        mov rdx,0
        div rbx
        cmp dl,09h
        jbe label_6
        add dl,07h

     label_6:
        add dl,30h
        mov[rdi],dl
        dec rdi
        dec rcx
        jnz label_5    

        print 1,1,result1,4
        

        exit:
             mov rax,60
             mov rdi,0
             syscall