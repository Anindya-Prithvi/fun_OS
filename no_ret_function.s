	.file	"no_ret_function.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "main: %p\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movq	8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	call	a
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "a has been called\0"
.LC2:
	.ascii "this will not print\0"
.LC3:
	.ascii "a: %p\12\0"
	.text
	.globl	a
	.def	a;	.scl	2;	.type	32;	.endef
	.seh_proc	a
a:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC1(%rip), %rcx
	call	puts
	call	b
	leaq	.LC2(%rip), %rcx
	call	puts
	movq	8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC4:
	.ascii "b has been called\0"
.LC5:
	.ascii "b: %p\12\0"
	.text
	.globl	b
	.def	b;	.scl	2;	.type	32;	.endef
	.seh_proc	b
b:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC4(%rip), %rcx
	call	puts
	movq	8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii "last function to be called\0"
.LC7:
	.ascii "c: %p\12\0"
	.text
	.globl	c
	.def	c;	.scl	2;	.type	32;	.endef
	.seh_proc	c
c:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC6(%rip), %rcx
	call	puts
	movq	8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
