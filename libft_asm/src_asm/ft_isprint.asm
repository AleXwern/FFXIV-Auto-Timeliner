section	.text
   global ft_isprint

;int		ft_isdigit(int c)
;Returns 1 if c is a printable character and has assossiated letter. Else 0.
;rdi=c
ft_isprint:
	lea		ecx, [rdi - 32]
	cmp		ecx, 95
	setb	al
	ret
