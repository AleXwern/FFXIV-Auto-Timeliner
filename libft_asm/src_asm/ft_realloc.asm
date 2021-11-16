section	.text
	global ft_realloc

extern malloc
extern free
extern ft_bzero

;void		*ft_realloc(void *ptr, size_t newlen, size_t oldlen)
;DON'T USE FOR NOW
;rdi=ptr	rsi=newlen	rdx=oldlen
ft_realloc:
	push	rdi			;push0
	push	rdx			;push1
	push	rsi			;push2
	mov		rdi, rsi
	call	malloc
	test	rax, rax
	jz		return		;if malloc returns null, return with null
	pop		rsi
	pop		rdx
	cmp		rsi, rdx
	cmovb	rsi, rdx
	lea		rdi, [rax + rsi]	;offset where new 
	sub		rsi, rdx
	call	ft_bzero
	mov		rax, rdi
	pop		rdi
	xor		rcx, rcx
memcpy:
	cmp		rcx, rdx
	jae		free_old
	movzx	r8d, byte [rdi + rcx]
	mov		byte [rax + rcx], r8b
	inc		rcx
	jmp		memcpy
free_old:
	push	rax
	call	free
	pop		rax
return:
	ret
