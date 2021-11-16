section	.text
   global ft_memalloc

extern malloc
extern ft_bzero

;void	*ft_memalloc(size_t size)
;Little bit of an extension to malloc. Allocates size bytes of memory but also sets all allocated bytes to 0.
;Really convinient in some cases as you can assume default values to be 0/NULL/false.
;rdi=size
ft_memalloc:
	push	rdi
	call	malloc
	pop		rsi
	test	rax, rax
	jz		return
	mov		rdi, rax
	call	ft_bzero
return:
	ret
