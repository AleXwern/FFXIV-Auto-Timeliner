section	.text
   global ft_isnegative

;int		ft_isnegative(int c)
;Returns 1 if c is a negaive number (less than 0). Else 0.
;rdi=c
ft_isnegative:
	mov		eax, edi
	shr		eax, 31		;Just shift the number right 31 times and return the remaining 1 or 0
	ret