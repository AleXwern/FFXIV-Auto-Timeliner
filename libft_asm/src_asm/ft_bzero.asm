section	.text
   global ft_bzero

;void	ft_bzero(void *s, size_t n)
;Sets n bytes from pointer s to 0.
;Should be used effectively with sizeof(X) so error checks are left out.
;rdi=x	rsi=n
ft_bzero:
	mov		rcx, 0					;RCX is used as counter for bytes set
	cmp		rcx, rsi
	jae		return					;Return if n is 0
bzero_loop:
	mov		byte [rdi+rcx], 0
	inc		rcx
	cmp		rcx, rsi
	jb		bzero_loop
return:
	ret
