section	.text
   global ft_strnew

extern malloc
extern ft_bzero

;char	*ft_strnew(size_t size)
;Allocates size+1 bytes of memory, fills the area with 0 and returns pointer to it.
;rdi=size
ft_strnew:
	inc		rdi
	push	rdi
	call	malloc
	pop		rsi
	test	rax, rax
	jz		return
	mov		rdi, rax
	call	ft_bzero
return:
	ret
