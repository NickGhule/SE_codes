%macro print 4
   mov rax,%1
   mov rdi,%2
   mov rsi,%3
   mov rdx,%4
   syscall
%endmacro


section .data
	msg_2 db"label_1 addition",10,13	
	db"shift method ",10,13	  
    db"enter your choice",10,13
    msg_2len equ $-msg_2
        
	msg_4 db "enter a number",10,13
	msg_4len equ $-msg_4
	msg_3 db "",10,13
	msg_3len equ $-msg_3


section .bss
	num resq 1
	numsg_2 resq 1
	buff resq 1
	choice resq 1


section .text
global main
main:
    menu:
		print 1,1,msg_3,msg_3len
    	print 1,1,msg_2,msg_2len
   		print 0,0,choice,2
            		 	
        cmp byte[choice],33h
 	    jae exit
             		 			
   		cmp byte[choice],31h
		je case1
             
        cmp byte[choice],32h
        je case2
		
    case1:
        print 1,1,msg_4,msg_4len
		print 0,0,num,17
		call accept
	
        mov r15,rbx
		
        print 1,1,msg_4,msg_4len
		print 0,0,num,17
		call accept
		mov r13,0

	    label_1:
            add r13,r15
		  	dec rbx
			jnz label_1
		mov rax,r13
		call display
		jmp main


	case2:
        print 1,1,msg_4,msg_4len
		print 0,0,num,17
		call accept
		
        mov r15,rbx
		print 1,1,msg_4,msg_4len
		print 0,0,num,17
		call accept

		mov r14,rbx
		mov rax,0
		mov rbx,r15
		mov rdx,r14
		mov rcx,64
		
        label_2:	
			shl rax,1
			rol rbx,1
			jnc label_3 
			add rax,rdx
			
            label_3:
                dec rcx
			    jnz label_2

		call display
		jmp main
		
    exit:
		print 60,0,msg_3,msg_3len


accept:
	mov r8,num
	mov r10,16
	mov rax,0
	mov rbx,0
    label_11:
        rol rbx,4
        mov al,byte[r8]
        cmp al,39h
	    jbe label_12
	    sub al,07h
	label_12:
	    sub al,30h
	    add rbx,rax
        inc r8
	    dec r10
	    jnz label_11
	    mov rax,rbx
	    call display
   	ret

		

display:     
          mov RSI,buff
          mov RCX,16

label_21:     
        rol RAX,4
        mov DL,AL
        AND DL,0fh
        cmp DL,09h
        jle label_22
        add DL,07h
label_22: 
        add DL,30h
        mov [RSI],DL
        add RSI,1
        dec RCX
        jnz label_21
        print 1,1,buff,16
    ret
