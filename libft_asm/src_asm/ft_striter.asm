section	.text
   global ft_striter

;void	ft_striter(char *s, void (*f)(char *))
;Performs function f to each character/substring s.
;rdi=s		rsi=(*f)(char *)
ft_striter:
	test	rdi, rdi
	jz		return
	test	rsi, rsi
	jz		return
	cmp		byte [rdi], 0		;Check NULLs and if the first character is not \0
	jz		return
striter_loop:
	call	rsi					;s is already in rdi so we can use call on rsi
	inc		rdi
	cmp		byte [rdi], 0
	jnz		striter_loop
return:
	ret
