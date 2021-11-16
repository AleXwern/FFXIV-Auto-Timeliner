section	.text
   global ft_isalpha

;int		ft_isalpha(int c)
;Returns 1 if c represents a character. Else 0.
;rdi=c
ft_isalpha:
	and		edi, -33	;The difference between 'A' and 'a' is the 3rd significant bit so we AND that out
	add		edi, -65
	cmp		edi, 26
	setb	al
	ret