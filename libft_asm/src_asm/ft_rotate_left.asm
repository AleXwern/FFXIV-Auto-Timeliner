section	.text
	global ft_rotate_left

;unsigned int	ft_rotate_left(unsigned int num, unsigned int n)
;Rotates integer num left by n bits. Bits that go over left border go back to right end.
;No apparent C implementation so I'll do it myself.
;rdi=num	rsi=num
ft_rotate_left:
	mov		ecx, esi
	rol		edi, cl
	mov		eax, edi
	ret
