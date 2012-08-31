	.file	"static.cpp"
	.section	.text._ZN3DogC2Eii,"axG",@progbits,_ZN3DogC5Eii,comdat
	.align 2
	.weak	_ZN3DogC2Eii
	.type	_ZN3DogC2Eii, @function
_ZN3DogC2Eii:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%eax)
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN3DogC2Eii, .-_ZN3DogC2Eii
	.text
	.align 2
	.globl	_ZN3Dog4growEi
	.type	_ZN3Dog4growEi, @function
_ZN3Dog4growEi:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %edx
	addl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE3:
	.size	_ZN3Dog4growEi, .-_ZN3Dog4growEi
	.section	.rodata
.LC0:
	.string	"age: %d, sex: %d\n"
	.text
	.align 2
	.globl	_ZN3Dog4infoEv
	.type	_ZN3Dog4infoEv, @function
_ZN3Dog4infoEv:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	_ZN3Dog4infoEv, .-_ZN3Dog4infoEv
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 8(%esp)
	movl	$2, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN3DogC1Eii
	movl	$10, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN3Dog4growEi
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN3Dog4infoEv
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.weak	_ZN3DogC1Eii
	.set	_ZN3DogC1Eii,_ZN3DogC2Eii
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
