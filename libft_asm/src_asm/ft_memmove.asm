extern ft_memcpy
section	.text
	global ft_memmove

;void	*ft_memmove(void *dst, const void *src, size_t len)
;Similar to memmove: moves n bytes from src to dst. In this case memory areas can overlap
;and in such cases is handled appropriately.
;Returns pointer to dst.
;rdi=dst	 rsi=src 	rdx=n
ft_memmove:
	xor		rax, rax
	test	rdi, rdi
	jz		return
	test	rsi, rsi
	jz		return
	xor		rcx, rcx
	cmp		rdi, rsi
	jb		memcpy_call
memmove_loop:
	cmp		rcx, rdx
	je		return
	movzx	r8d, byte [rsi + rcx]
	mov		byte [rdi + rcx], r8b
	inc		rcx
	jmp		memmove_loop
memcpy_call:
	call	ft_memcpy WRT ..plt
return:
	mov		rax, rdi
	ret
