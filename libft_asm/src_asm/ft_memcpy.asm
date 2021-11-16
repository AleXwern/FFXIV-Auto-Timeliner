section	.text
	global ft_memcpy

;void	*ft_memcpy(void *dst, const void *src, size_t n)
;Moves n bytes from src to dst. Memory areas should not overlap.
;Returns pointer to dst.
;rdi=dst	 rsi=src 	rdx=n
ft_memcpy:
	xor		rcx, rcx
	cmp		rcx, rdx
	je		return
memcpy_loop:
	movzx	r8d, byte [rsi + rcx]
	mov		byte [rdi + rcx], r8b
	inc		rcx
	cmp		rcx, rdx
	jb		memcpy_loop
return:
	mov		rax, rdi
	ret
