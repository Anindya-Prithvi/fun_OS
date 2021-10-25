	.file	"a2.c"
	.text
	.section	.rodata
.LC0:
	.string	"Calloc failed"
.LC1:
	.string	"Writing to STDOUT failed\n"
	.text
	.globl	mythread
	.type	mythread, @function
mythread:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movq	%rdi, -120(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-120(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, -92(%rbp)
	movq	-80(%rbp), %rax
	movl	16(%rax), %eax
	movl	%eax, -88(%rbp)
	movq	-80(%rbp), %rax
	movl	20(%rax), %eax
	movl	%eax, -84(%rbp)
	movq	-80(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -72(%rbp)
	movl	$0, -96(%rbp)
	movl	$4, %esi
	movl	$6, %edi
	call	calloc@PLT
	movq	%rax, -64(%rbp)
	cmpq	$0, -64(%rbp)
	jne	.L2
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	movl	$0, -104(%rbp)
	jmp	.L3
.L10:
	movl	$0, -100(%rbp)
	jmp	.L4
.L9:
	cmpl	$0, -100(%rbp)
	jne	.L5
	movl	-104(%rbp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	subl	%edx, %eax
	movl	%eax, %ecx
	movl	-100(%rbp), %eax
	addl	%ecx, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -92(%rbp)
	je	.L16
	addl	$1, -96(%rbp)
	jmp	.L8
.L5:
	movl	-100(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-104(%rbp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	movl	-100(%rbp), %eax
	addl	%esi, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-100(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rsi
	movq	-64(%rbp), %rax
	addq	%rsi, %rax
	addl	%ecx, %edx
	movl	%edx, (%rax)
.L8:
	addl	$1, -100(%rbp)
.L4:
	movl	-100(%rbp), %eax
	cmpl	-84(%rbp), %eax
	jl	.L9
	jmp	.L7
.L16:
	nop
.L7:
	addl	$1, -104(%rbp)
.L3:
	movl	-104(%rbp), %eax
	cmpl	-88(%rbp), %eax
	jl	.L10
	movl	$0, -100(%rbp)
	jmp	.L11
.L13:
	movl	-100(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	-100(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-64(%rbp), %rdx
	addq	%rdx, %rcx
	cltd
	idivl	-96(%rbp)
	movl	%eax, (%rcx)
	movabsq	$2336927755366786387, %rax
	movabsq	$7955443211349073952, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movabsq	$2322203881627346285, %rax
	movq	%rax, -32(%rbp)
	movw	$0, -24(%rbp)
	movb	$0, -22(%rbp)
	movl	-100(%rbp), %eax
	addl	$49, %eax
	movb	%al, -27(%rbp)
	movb	$10, -22(%rbp)
	movl	-92(%rbp), %eax
	movb	%al, -40(%rbp)
	movl	-100(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	addl	$48, %eax
	movb	%al, -25(%rbp)
	movl	-100(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
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
	movb	%al, -24(%rbp)
	movl	-100(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
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
	movl	-100(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
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
	movb	%al, -23(%rbp)
	leaq	-48(%rbp), %rax
	movl	$27, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	movq	%rax, -56(%rbp)
	cmpq	$-1, -56(%rbp)
	jne	.L12
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L12:
	addl	$1, -100(%rbp)
.L11:
	cmpl	$5, -100(%rbp)
	jle	.L13
	movq	-64(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L15
	call	__stack_chk_fail@PLT
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	mythread, .-mythread
	.section	.rodata
.LC2:
	.string	"student_record.csv"
.LC3:
	.string	"FILE could not be opened\n"
.LC4:
	.string	"reading failed\n"
.LC5:
	.string	"Closing failed\n"
.LC6:
	.string	"\n"
.LC7:
	.string	"Malloc failed"
.LC8:
	.string	","
.LC9:
	.string	"Thread failed"
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
	pushq	%rbx
	subq	$280, %rsp
	.cfi_offset 3, -24
	movl	%edi, -276(%rbp)
	movq	%rsi, -288(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -256(%rbp)
	cmpl	$-1, -256(%rbp)
	jne	.L18
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L18:
	movl	$1, %esi
	movl	$8192, %edi
	call	calloc@PLT
	movq	%rax, -176(%rbp)
	cmpq	$0, -176(%rbp)
	jne	.L19
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L19:
	movq	-176(%rbp), %rcx
	movl	-256(%rbp), %eax
	movl	$8192, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movq	%rax, -168(%rbp)
	cmpq	$-1, -168(%rbp)
	jne	.L20
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$15, %edx
	movl	$1, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L20:
	movl	-256(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	cmpl	$-1, %eax
	jne	.L21
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$15, %edx
	movl	$1, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L21:
	movq	$0, -208(%rbp)
	leaq	-208(%rbp), %rdx
	movq	-176(%rbp), %rax
	leaq	.LC6(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strtok_r@PLT
	movq	%rax, -200(%rbp)
	leaq	-208(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok_r@PLT
	movq	%rax, -200(%rbp)
	movl	$7, -268(%rbp)
	movq	-208(%rbp), %rax
	movq	%rax, -192(%rbp)
	movl	$0, -264(%rbp)
	jmp	.L22
.L23:
	movq	-192(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$10, %al
	jne	.L22
	addl	$1, -264(%rbp)
.L22:
	addq	$1, -192(%rbp)
	movq	-192(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L23
	addl	$1, -264(%rbp)
	movl	-264(%rbp), %eax
	imull	-268(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -160(%rbp)
	cmpq	$0, -160(%rbp)
	jne	.L24
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L24:
	movl	$0, -268(%rbp)
	jmp	.L25
.L30:
	movl	$0, -260(%rbp)
	leaq	-112(%rbp), %rdx
	movq	-200(%rbp), %rax
	leaq	.LC8(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strtok_r@PLT
	movq	%rax, -184(%rbp)
	jmp	.L26
.L29:
	cmpl	$1, -260(%rbp)
	jne	.L27
	movq	-184(%rbp), %rax
	movzbl	(%rax), %ecx
	movl	-268(%rbp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	subl	%edx, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-160(%rbp), %rax
	addq	%rax, %rdx
	movsbl	%cl, %eax
	movl	%eax, (%rdx)
	jmp	.L28
.L27:
	cmpl	$0, -260(%rbp)
	jle	.L28
	movl	-268(%rbp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	subl	%edx, %eax
	movl	%eax, %ecx
	movl	-260(%rbp), %eax
	addl	%ecx, %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-160(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movq	-184(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, (%rbx)
.L28:
	addl	$1, -260(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok_r@PLT
	movq	%rax, -184(%rbp)
.L26:
	cmpq	$0, -184(%rbp)
	jne	.L29
	addl	$1, -268(%rbp)
	leaq	-208(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok_r@PLT
	movq	%rax, -200(%rbp)
.L25:
	cmpq	$0, -200(%rbp)
	jne	.L30
	movb	$65, -144(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	movl	-264(%rbp), %eax
	movl	%eax, -128(%rbp)
	movl	$7, -124(%rbp)
	movb	$66, -112(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -104(%rbp)
	movl	-264(%rbp), %eax
	movl	%eax, -96(%rbp)
	movl	$7, -92(%rbp)
	leaq	-144(%rbp), %rdx
	leaq	-240(%rbp), %rax
	movq	%rdx, %rcx
	leaq	mythread(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	movl	%eax, -252(%rbp)
	cmpl	$0, -252(%rbp)
	je	.L31
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L31:
	leaq	-112(%rbp), %rdx
	leaq	-232(%rbp), %rax
	movq	%rdx, %rcx
	leaq	mythread(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	movl	%eax, -248(%rbp)
	cmpl	$0, -248(%rbp)
	je	.L32
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L32:
	movq	-232(%rbp), %rax
	leaq	-216(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	pthread_join@PLT
	movl	%eax, -248(%rbp)
	cmpl	$0, -248(%rbp)
	je	.L33
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L33:
	movq	-240(%rbp), %rax
	leaq	-224(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	pthread_join@PLT
	movl	%eax, -252(%rbp)
	cmpl	$0, -252(%rbp)
	je	.L34
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L34:
	movl	$0, -260(%rbp)
	jmp	.L35
.L36:
	movq	-224(%rbp), %rdx
	movl	-260(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-216(%rbp), %rcx
	movl	-260(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %edx
	movl	-260(%rbp), %eax
	cltq
	movl	%edx, -80(%rbp,%rax,4)
	addl	$1, -260(%rbp)
.L35:
	cmpl	$5, -260(%rbp)
	jle	.L36
	movq	-224(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-216(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, -260(%rbp)
	jmp	.L37
.L39:
	movl	-260(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %eax
	movl	%eax, -244(%rbp)
	movabsq	$8243124715061011790, %rax
	movabsq	$9071108911621985, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movw	$0, -32(%rbp)
	movb	$0, -30(%rbp)
	movl	-260(%rbp), %eax
	addl	$49, %eax
	movb	%al, -37(%rbp)
	movb	$10, -31(%rbp)
	movl	-244(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	addl	$48, %eax
	movb	%al, -34(%rbp)
	movl	-244(%rbp), %edx
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
	movb	%al, -33(%rbp)
	movl	-244(%rbp), %eax
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
	movl	-244(%rbp), %eax
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
	movb	%al, -32(%rbp)
	leaq	-48(%rbp), %rax
	movl	$19, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	movq	%rax, -152(%rbp)
	cmpq	$-1, -152(%rbp)
	jne	.L38
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L38:
	addl	$1, -260(%rbp)
.L37:
	cmpl	$5, -260(%rbp)
	jle	.L39
	movl	$0, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L41
	call	__stack_chk_fail@PLT
.L41:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
