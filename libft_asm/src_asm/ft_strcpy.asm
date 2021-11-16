section	.text
   global ft_strcpy

;char	*ft_strcpy(char *dst, const char *src)
;Copies src over dst including the trailing null byte. Dst must have enough space.
;rdi=dst		rsi=src
ft_strcpy:
	xor		rcx, rcx
strcpy_loop:
	movzx	eax, byte [rsi + rcx]
	mov		byte [rdi + rcx], al
	add		rcx, 1
	cmp		eax, 0
	jnz		strcpy_loop
	mov		rax, rdi
	ret
