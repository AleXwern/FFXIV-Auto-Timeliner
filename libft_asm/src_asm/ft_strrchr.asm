section	.text
   global ft_strrchr

extern ft_strlen

;char	*ft_strrchr(const char *str, int c)
;Searches str for the last occurence of c and return a pointer to it.
;rdi=str		rsi=c
ft_strrchr:
	call	ft_strlen				;str length to RAX
strrchr_loop:
	cmp		byte [rdi + rax], sil	;if characters match, return pointer
	je		setptr
	cmp		rax, 0					;Basically if index is about to go below 0, return NULL
	jz		return
	dec		rax
	jmp		strrchr_loop
setptr:
	lea		rax, [rdi + rax]
	ret
return:
	xor		rax, rax
	ret
