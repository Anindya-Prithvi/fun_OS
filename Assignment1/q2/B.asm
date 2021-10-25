extern write;
extern C;

section .data
	wtext db "---",10,"Welcome to B",10,10
    ltext db 10,"The above was said by a syscall",10,"BigBrain LittleEndian :)"
    etext db 10,"Time to call C, bye",10

section .text
    global B

B:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     [rbp-24], rdi
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, wtext
        mov     rdx, 18 ; length of text
        syscall
        lea     rcx, [rbp-24]
        mov		rax, 1
        mov 	rdi, 1
        mov 	rsi, rcx
        mov 	rdx, 8
        syscall

        mov     rax, 1
        mov     rdi, 1
        mov     rsi, ltext
        mov     rdx, 57 ; length of text
        syscall
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, etext
        mov     rdx, 21 ; length of text
        syscall
        mov     long[rbp-8], C
        mov     rax, [rbp-8]
        mov     rcx, rax
        mov 	rax, rcx
        mov 	[rbp+8], rax

        nop
        leave
        ret