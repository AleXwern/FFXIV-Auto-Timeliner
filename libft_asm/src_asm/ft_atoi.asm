section .text
	global ft_atoi

;int		ft_atoi(const char *str)
;Takes a NULL terminated string str and returns signed 32-bit value it represents.
;for now we are only checking for whitespace and minus signs. Get it working and then
;worry about the rest.
ft_atoi:
	xor		rax, rax
	test	rdi, rdi
	jz		exit_zero
	cmp		byte [rdi], 0x2D	;0x2D is '-' and 0x2B is '+'
	jz		set_negflag			;If value is '-' we set value to negative, else continue
	mov		ecx, 1
	jmp		status_comparison
set_negflag:					;0x2D
	mov		ecx, -1
	inc		rdi
status_comparison:
	mov		dl, byte [rdi]
	lea		esi, [rdx - 0x30]	;0x30 = '0'
	cmp		sil, 9
	ja		std_exit
	cmp		sil, 0
	jb		std_exit
	imul	eax, 10				;If we fall lthought checks we calc our new number
	add		eax, esi
	inc		rdi
	jmp		status_comparison
std_exit:
	imul	eax, ecx			;If checks fail we are done here. Calc the final value
exit_zero:
	ret
