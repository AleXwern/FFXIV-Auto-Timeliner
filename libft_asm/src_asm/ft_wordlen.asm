section	.text
   global ft_wordlen

;int		ft_wordlen(char const *str, char del)
;Similar to ft_strlen, returns a length of string str except wordlen also has delimiter del that also
;serves as a cutout point
;rdi=str		rsi=del
ft_wordlen:
	xor		rax, rax
lenloop:
	cmp		byte [rdi + rax], 0
	je		return
	cmp		byte [rdi + rax], sil
	je		return
	inc		rax
	jmp		lenloop
return:
	ret
