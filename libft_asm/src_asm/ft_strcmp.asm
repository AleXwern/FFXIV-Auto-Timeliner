section	.text
   global ft_strcmp

;int		ft_strcmp(const char *s1, const char *s2)
;Compares null terminated strings s1 and s2 and returns the subtraction of
;the first found different character. Similar concept as ASM instruction CMP.
;rdi=s1		rsi=s2
ft_strcmp:
	movzx	eax, byte [rdi]
	cmp		al, byte [rsi]
	jne		return
	cmp		byte [rdi], 0
	jz		return
	cmp		byte [rsi], 0
	jz		return
	inc		rdi
	inc		rsi
	jmp		ft_strcmp
return:
	movzx	esi, byte [rsi]
	sub		eax, esi
	ret
