section	.text
   global ft_memset

;void	*ft_memset(void *b, int c, size_t len)
;Sets len bytes from pointer b to c and returns the pointer to it.
;rdi=b	rsi=c	rdx=len
ft_memset:
	test	rdi, rdi
	jz		return					;jump to return if pointer is null
	mov		rcx, 0					;RCX is used as counter for bytes set
memset_loop:
	mov		byte [rdi+rcx], sil
	inc		rcx
	cmp		rcx, rdx
	jb		memset_loop				;Continue loop is len bytes are not set
return:
	mov		rax, rdi
	ret
