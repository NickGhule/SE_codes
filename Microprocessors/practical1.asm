%macro scall 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section.data
	cnt db 3
	arr dq 12h,3h,-9h

section.bss
	pcnt resb 1
	ncnt resb 1
	buff resq 1
section.txt
	global main

main:
	mov rsi,arr
	mov rcx,0
	mov rdx,0
	mov rbx,cnt
	mov rdx,[rsi]

cmp rdx,0000000000000000h
js negative
inc rcx
jmp next
negative:	inc rdx

next: 	add rsi,8
      	dec rbx
      	jnz up

test: 	mov [pcnt],rcx
        mov [ncnt],rdx
scall 1,1,m1,m1len
mov rax,[pcnt]
call display

scall 1,1,m2,m2len
mov rdx,[ncnt]
call display

mov rdx,60
mov rbx,0
syscall

display:
	mov rcx,16
	mov rsi,buff

up1:
	rol rax,4
	mov dl,al
	and dl,0fh
	add dl,30h
	
	mov [rsi],dl
	add rsi,1
	dec rcx
	jnz up1
ret