section	.text
   global ft_strequ

;int		ft_strequ(char const *s1, char const *s2)
;Compares null terminated strings s1 and s2 and returns 1 if they match and 0 if they don't.
;rdi=s1		rsi=s2
ft_strequ:
	xor		rax, rax
	jmp		strequ_check
strequ_set:
	inc		rax
	cmp		r8b, byte [rsi + rax - 1]
	jne		return_zero				;if characters are not same we return always 0
strequ_check:
	mov		r8b, byte [rdi + rax]
	test	r8b, r8b				;If result is 0 we preapre outcome
	jnz		strequ_set				;if not, we'll checkhow they compare
	cmp		byte [rsi + rax], r8b
	sete	al						;if both are equal set to 1, else 0
	movzx	eax, al					;zero extend to make sure eax is exactly 1/0
	ret
return_zero:
	mov		eax, 0
	ret
