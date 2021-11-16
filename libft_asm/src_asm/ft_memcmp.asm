section	.text
   global ft_memcmp

;int		ft_memcmp(const void *s1, const void *s2, size_t n)
;Compares first n bytes of both s1 an s2.
;Return the difference (byte s1 - byte s2) if difference was found within n bytes. Else 0.
;rdi=s1	 rsi=s2 	rdx=n
ft_memcmp:
	xor		eax, eax
	test	rdi, rdi	;Check if s1 or s2 are NULL
	jz		return
	test	rsi, rsi
	jz		return
	cmp		rdi, rsi	;Check if s1 and s2 are the same
	je		return
	xor		rcx, rcx	;Zero out counter
memcmp_loop:
	cmp		rdx, rcx	;Return 0 if n is 0 or n loops have been made
	je		return
	movzx	eax, byte [rdi + rcx]
	movzx	r8d, byte [rsi + rcx]
	inc		rcx
	cmp		al, r8b
	je		memcmp_loop
return_diff:
	sub		eax, r8d
	ret
return:
	xor		eax, eax
	ret
