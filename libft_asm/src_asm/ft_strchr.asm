section	.text
   global ft_strchr

;char	*ft_strchr(const char *str, int c)
;Returns pointer to the first character c in string str
;This feels like it has a little bit too many comparisons but it'll do for now.
;rdi=str	rsi=c
ft_strchr:
	xor		rax, rax
strchr_scan:
	cmp		byte [rdi], 0
	jz		return
	cmp		byte [rdi], sil
	cmove	rax, rdi
	inc		rdi
	cmp		rax, 0
	jz		strchr_scan
return:
	cmp		sil, 0 
	cmove	rax, rdi
	ret
