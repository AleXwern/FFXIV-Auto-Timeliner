section	.text
   global ft_isdigit

;int		ft_isdigit(int c)
;Returns 1 if c represents a number. Else 0.
;rdi=c
ft_isdigit:
	add		edi, -48
	cmp		edi, 10
	setb	al
	ret