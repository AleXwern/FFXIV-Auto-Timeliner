section	.text
   global ft_memchr

;void	*ft_memchr(const void *s, int c, size_t n)
;Searches the first n bytes from s the first instance of c.
;Returns a pointer to the first occurence of c or NULL is there was no c.
;rdi=s	rsi=c 	rdx=n
ft_memchr:
	xor		rax, rax
	test	rdi, rdi			;test that s is not NULL
	jz		return
	xor		rcx, rcx
memchr_loop:
	test	rdx, rdx			;Check if n is 0 at any point. If is go straigt to ret
	jz		return
	cmp		byte [rdi], sil		;If c is found return current stored pointer
	je		prep_return
	inc		rdi
	add		rdx, -1
	jmp		memchr_loop
prep_return:
	mov		rax, rdi
return:
	ret
