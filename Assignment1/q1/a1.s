	.file	"a1.c"
	.text
	.section	.rodata
.LC0:
	.string	"Writing to STDOUT failed\n"
.LC1:
	.string	"\n"
.LC2:
	.string	"Could not tokenize\n"
.LC3:
	.string	","
	.text
	.globl	operate
	.type	operate, @function
operate:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$208, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movl	%edi, %eax
	movq	%rsi, -224(%rbp)
	movb	%al, -212(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %r12
	movabsq	$2334956331069302867, %rax
	movabsq	$7598825368042173555, %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movabsq	$7310222244475597667, %rax
	movabsq	$35658687673443, %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movb	$0, -48(%rbp)
	movzbl	-212(%rbp), %eax
	movb	%al, -50(%rbp)
	movb	$10, -49(%rbp)
	leaq	-80(%rbp), %rax
	movl	$33, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	movq	%rax, -144(%rbp)
	cmpq	$-1, -144(%rbp)
	jne	.L2
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	leaq	-184(%rbp), %rdx
	movq	-224(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strtok_r@PLT
	movq	%rax, -160(%rbp)
	cmpq	$0, -160(%rbp)
	jne	.L3
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$19, %edx
	movl	$1, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L3:
	movl	$0, -196(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -168(%rbp)
	jmp	.L4
.L6:
	movq	-168(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	jne	.L5
	addl	$1, -196(%rbp)
.L5:
	addq	$1, -168(%rbp)
.L4:
	movq	-168(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$13, %al
	jne	.L6
	subl	$1, -196(%rbp)
	movl	-196(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -136(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -240(%rbp)
	movq	$0, -232(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r14
	movl	$0, %r15d
	cltq
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -128(%rbp)
	movl	$0, -200(%rbp)
	jmp	.L7
.L8:
	movq	-128(%rbp), %rax
	movl	-200(%rbp), %edx
	movslq	%edx, %rdx
	movl	$0, (%rax,%rdx,4)
	addl	$1, -200(%rbp)
.L7:
	movl	-200(%rbp), %eax
	cmpl	-196(%rbp), %eax
	jl	.L8
	leaq	-184(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok_r@PLT
	movq	%rax, -160(%rbp)
	movl	$0, -192(%rbp)
	jmp	.L9
.L16:
	movl	$0, -200(%rbp)
	leaq	-176(%rbp), %rdx
	movq	-160(%rbp), %rax
	leaq	.LC3(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strtok_r@PLT
	movq	%rax, -152(%rbp)
	jmp	.L10
.L15:
	cmpl	$1, -200(%rbp)
	jne	.L11
	movq	-152(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, -212(%rbp)
	jne	.L22
.L11:
	cmpl	$1, -200(%rbp)
	jne	.L13
	movq	-152(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, -212(%rbp)
	jne	.L13
	addl	$1, -192(%rbp)
.L13:
	cmpl	$1, -200(%rbp)
	jle	.L14
	movl	-200(%rbp), %eax
	leal	-2(%rax), %edx
	movq	-128(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ebx
	movq	-152(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, %ecx
	movl	-200(%rbp), %eax
	leal	-2(%rax), %edx
	addl	%ebx, %ecx
	movq	-128(%rbp), %rax
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
.L14:
	addl	$1, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok_r@PLT
	movq	%rax, -152(%rbp)
.L10:
	cmpq	$0, -152(%rbp)
	jne	.L15
	jmp	.L12
.L22:
	nop
.L12:
	leaq	-184(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok_r@PLT
	movq	%rax, -160(%rbp)
.L9:
	cmpq	$0, -160(%rbp)
	jne	.L16
	movl	$0, -200(%rbp)
	jmp	.L17
.L19:
	movq	-128(%rbp), %rax
	movl	-200(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cltd
	idivl	-192(%rbp)
	movl	%eax, -188(%rbp)
	movabsq	$7308619160722043713, %rax
	movabsq	$35434019189870, %rdx
	movq	%rax, -112(%rbp)
	movq	%rdx, -104(%rbp)
	movw	$0, -96(%rbp)
	movb	$0, -94(%rbp)
	movl	-200(%rbp), %eax
	addl	$49, %eax
	movb	%al, -101(%rbp)
	movb	$10, -95(%rbp)
	movl	-188(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	addl	$48, %eax
	movb	%al, -98(%rbp)
	movl	-188(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1374389535, %rax, %rax
	shrq	$32, %rax
	sarl	$5, %eax
	movl	%edx, %ecx
	sarl	$31, %ecx
	subl	%ecx, %eax
	imull	$100, %eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	addl	$48, %eax
	movb	%al, -97(%rbp)
	movl	-188(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, %ecx
	movl	-188(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	subl	%edx, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	addl	$48, %eax
	movb	%al, -96(%rbp)
	leaq	-112(%rbp), %rax
	movl	$19, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	movq	%rax, -120(%rbp)
	cmpq	$-1, -120(%rbp)
	jne	.L18
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L18:
	addl	$1, -200(%rbp)
.L17:
	movl	-200(%rbp), %eax
	cmpl	-196(%rbp), %eax
	jl	.L19
	nop
	movq	%r12, %rsp
	movq	-40(%rbp), %rax
	subq	%fs:40, %rax
	je	.L21
	call	__stack_chk_fail@PLT
.L21:
	leaq	-32(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	operate, .-operate
	.section	.rodata
.LC4:
	.string	"student_record.csv"
.LC5:
	.string	"FILE could not be opened\n"
	.align 8
.LC6:
	.string	"Reading from file descriptor to buf failed\n"
.LC7:
	.string	"Closing failed\n"
.LC8:
	.string	"Forking failed\n"
.LC9:
	.string	"Waiting failed\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8256, %rsp
	movl	%edi, -8244(%rbp)
	movq	%rsi, -8256(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -8228(%rbp)
	cmpl	$-1, -8228(%rbp)
	jne	.L24
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L24:
	leaq	-8208(%rbp), %rcx
	movl	-8228(%rbp), %eax
	movl	$8192, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movq	%rax, -8216(%rbp)
	cmpq	$-1, -8216(%rbp)
	jne	.L25
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$43, %edx
	movl	$1, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L25:
	movl	-8228(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	cmpl	$-1, %eax
	jne	.L26
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$15, %edx
	movl	$1, %esi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L26:
	call	fork@PLT
	movl	%eax, -8224(%rbp)
	cmpl	$0, -8224(%rbp)
	jns	.L27
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$15, %edx
	movl	$1, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L27:
	cmpl	$0, -8224(%rbp)
	jne	.L28
	leaq	-8208(%rbp), %rax
	movq	%rax, %rsi
	movl	$65, %edi
	call	operate
	movl	$0, %edi
	call	exit@PLT
.L28:
	movl	-8224(%rbp), %eax
	movl	$0, %edx
	movl	$0, %esi
	movl	%eax, %edi
	call	waitpid@PLT
	movl	%eax, -8220(%rbp)
	cmpl	$-1, -8220(%rbp)
	jne	.L29
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$15, %edx
	movl	$1, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
.L29:
	leaq	-8208(%rbp), %rax
	movq	%rax, %rsi
	movl	$66, %edi
	call	operate
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L31
	call	__stack_chk_fail@PLT
.L31:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
