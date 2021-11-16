section	.text
   global ft_isascii

;int		ft_isascii(int c)
;Returns 1 if c represents a ASCII character. Else 0.
;Admittedly I have never ever seen any use for this but it's part of LIBFT so here we go.
;rdi=c
ft_isascii:
	cmp		edi, 128
	setb	al
	ret