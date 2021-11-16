section	.text
   global ft_strnequ

;int		ft_strnequ(char const *s1, char const *s2, size_t n)
;
;rdi=s1		rsi=s2		rdx=n
ft_strnequ:
	xor		rcx, rcx
strnequ:
	movzx	eax, byte [rdi + rcx]
	cmp		al, byte [rsi + rcx]
	jne		return
	cmp		al, 0
	jz		return
	cmp		rcx, rdx
	jae		return
	inc		rcx
	jmp		strnequ
return:
	cmp		al, byte [rsi + rcx]
	sete	al
	ret
