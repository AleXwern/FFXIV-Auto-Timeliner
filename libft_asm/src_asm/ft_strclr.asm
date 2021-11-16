section	.text
   global ft_strclr

;void	ft_strclr(char *s)
;Fills null terminated string with null bytes
;rdi=s
ft_strclr:
	cmp		byte [rdi], 0
	jz		return
set_null:
	mov		byte [rdi], 0
	inc		rdi
	cmp		byte [rdi], 0
	jne		set_null
return:
	ret

