section	.text
   global ft_strncmp

;int		ft_strncmp(const char *s1, const char *s2, size_t n)
;Compares up to n characters between s1 and s2. returns results when any of 3 is true.
;1. n characters are read
;2. meets null byte
;3. there's difference
;rdi=s1		rsi=s2		rdx=n
ft_strncmp:
	xor		eax, eax
	xor		rcx, rcx
	test	rdx, rdx
	jz		return
	jmp		check
strncmp_loop:
	inc		rcx
check:
	movzx	r8d, byte [rdi + rcx]
	cmp		r8, 0
	jz		subtract
	cmp		byte [rsi + rcx], r8b
	jne		subtract
	cmp		rcx, rdx
	jae		subtract
	jmp		strncmp_loop
subtract:
	cmp		rcx, rdx
	je		return
	movzx	eax, byte [rdi + rcx]
	movzx	edx, byte [rsi + rcx]
	sub		eax, edx
return:
	ret
