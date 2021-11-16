section	.text
   global ft_strncat

;char	*ft_strncat(char *dest, const char *src, size_t n)
;Appends n characters from string src to dest, overwriting the null character.
;Even though copied size is limited to maximum of n, the dest still must have enough space
;and too big of n can/will cause buffer overrun.
;rdi=dest		rsi=src		rdx=n
ft_strncat:
	xor		r8, r8
	xor		r9, r9
	jmp		check
dstlen:
	inc		r8
check:
	cmp		byte [rdi + r8], 0
	jnz		dstlen
	jmp		loop_check
strncat_loop:
	movzx	eax, byte [rsi + r9]
	mov		byte [rdi + r8], al
	inc		r8
	inc		r9
loop_check:
	cmp		byte [rsi + r9], 0
	jz		return
	cmp		r9, rdx
	je		return
	jmp		strncat_loop
return:
	mov		byte [rdi + r8], 0
	mov		rax, rdi
	ret
