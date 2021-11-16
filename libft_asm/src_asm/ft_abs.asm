section .text
	global ft_abs

;int		ft_abs(int num)
;Takes integer num and returns positive (absolute) value.
ft_abs:
	mov		eax, edi
	neg		eax
	cmovl	eax, edi
	
	ret
