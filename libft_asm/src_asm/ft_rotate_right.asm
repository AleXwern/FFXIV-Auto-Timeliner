section	.text
	global ft_rotate_right

;unsigned int	ft_rotate_right(unsigned int num, unsigned int n)
;Rotates integer num right by n bits. Bits that go over right border go back to left end.
;No apparent C implementation so I'll do it myself.
;rdi=num	rsi=num
ft_rotate_right:
	mov		ecx, esi
	ror		edi, cl
	mov		eax, edi
	ret
