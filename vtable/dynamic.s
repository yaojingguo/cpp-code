	.file	"dynamic.cpp"
	.section	.text._ZN6WeaponC2Ev,"axG",@progbits,_ZN6WeaponC5Ev,comdat
	.align 2
	.weak	_ZN6WeaponC2Ev
	.type	_ZN6WeaponC2Ev, @function
_ZN6WeaponC2Ev:
.LFB1:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	$_ZTV6Weapon+8, (%eax)
	movl	8(%ebp), %eax
	movl	$9, 4(%eax)
	popl	%ebp
	ret
.LFE1:
	.size	_ZN6WeaponC2Ev, .-_ZN6WeaponC2Ev
	.section	.text._ZN6Weapon4saveEi,"axG",@progbits,_ZN6Weapon4saveEi,comdat
	.align 2
	.weak	_ZN6Weapon4saveEi
	.type	_ZN6Weapon4saveEi, @function
_ZN6Weapon4saveEi:
.LFB3:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	addl	$1, %eax
	popl	%ebp
	ret
.LFE3:
	.size	_ZN6Weapon4saveEi, .-_ZN6Weapon4saveEi
	.section	.text._ZN6BomberC2Ev,"axG",@progbits,_ZN6BomberC5Ev,comdat
	.align 2
	.weak	_ZN6BomberC2Ev
	.type	_ZN6BomberC2Ev, @function
_ZN6BomberC2Ev:
.LFB5:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN6WeaponC2Ev
	movl	8(%ebp), %eax
	movl	$_ZTV6Bomber+8, (%eax)
	movl	8(%ebp), %eax
	movl	$99, 12(%eax)
	leave
	ret
.LFE5:
	.size	_ZN6BomberC2Ev, .-_ZN6BomberC2Ev
	.text
	.align 2
	.globl	_ZN6Bomber4killEi
	.type	_ZN6Bomber4killEi, @function
_ZN6Bomber4killEi:
.LFB7:
	pushl	%ebp
	movl	%esp, %ebp
	cmpl	$10, 12(%ebp)
	jle	.L5
	movl	12(%ebp), %eax
	subl	$10, %eax
	jmp	.L6
.L5:
	movl	$0, %eax
.L6:
	popl	%ebp
	ret
.LFE7:
	.size	_ZN6Bomber4killEi, .-_ZN6Bomber4killEi
	.globl	main
	.type	main, @function
main:
.LFB8:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	movl	$16, (%esp)
	call	_Znwj
	movl	%eax, %ebx
	movl	%ebx, (%esp)
	call	_ZN6BomberC1Ev
	movl	%ebx, 24(%esp)
	movl	24(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	$10, 4(%esp)
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE8:
	.size	main, .-main
	.weak	_ZTV6Bomber
	.section	.rodata._ZTV6Bomber,"aG",@progbits,_ZTV6Bomber,comdat
	.align 8
	.type	_ZTV6Bomber, @object
	.size	_ZTV6Bomber, 16
_ZTV6Bomber:
	.long	0
	.long	_ZTI6Bomber
	.long	_ZN6Bomber4killEi
	.long	_ZN6Weapon4saveEi
	.weak	_ZTV6Weapon
	.section	.rodata._ZTV6Weapon,"aG",@progbits,_ZTV6Weapon,comdat
	.align 8
	.type	_ZTV6Weapon, @object
	.size	_ZTV6Weapon, 16
_ZTV6Weapon:
	.long	0
	.long	_ZTI6Weapon
	.long	__cxa_pure_virtual
	.long	_ZN6Weapon4saveEi
	.weak	_ZTI6Bomber
	.section	.rodata._ZTI6Bomber,"aG",@progbits,_ZTI6Bomber,comdat
	.align 4
	.type	_ZTI6Bomber, @object
	.size	_ZTI6Bomber, 12
_ZTI6Bomber:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS6Bomber
	.long	_ZTI6Weapon
	.weak	_ZTS6Bomber
	.section	.rodata._ZTS6Bomber,"aG",@progbits,_ZTS6Bomber,comdat
	.type	_ZTS6Bomber, @object
	.size	_ZTS6Bomber, 8
_ZTS6Bomber:
	.string	"6Bomber"
	.weak	_ZTS6Weapon
	.section	.rodata._ZTS6Weapon,"aG",@progbits,_ZTS6Weapon,comdat
	.type	_ZTS6Weapon, @object
	.size	_ZTS6Weapon, 8
_ZTS6Weapon:
	.string	"6Weapon"
	.weak	_ZTI6Weapon
	.section	.rodata._ZTI6Weapon,"aG",@progbits,_ZTI6Weapon,comdat
	.align 4
	.type	_ZTI6Weapon, @object
	.size	_ZTI6Weapon, 8
_ZTI6Weapon:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS6Weapon
	.weak	_ZN6WeaponC1Ev
	.set	_ZN6WeaponC1Ev,_ZN6WeaponC2Ev
	.weak	_ZN6BomberC1Ev
	.set	_ZN6BomberC1Ev,_ZN6BomberC2Ev
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
