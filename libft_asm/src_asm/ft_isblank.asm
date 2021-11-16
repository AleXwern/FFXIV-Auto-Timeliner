section	.text
   global ft_isblank

;int		ft_isblank(int c)
;Returns 1 if c represents a blank character. Else 0.
;Black characters are the following: HTab, new line, VTab, form feed, carriage return and whitespace.
;rdi=c
ft_isblank:
	xor		rax, rax
	lea		ecx, [rdi - 9]
	cmp		ecx, 5
	setb	al
	cmp		edi, 0x20
	sete	cl
	or		al, cl
	ret
