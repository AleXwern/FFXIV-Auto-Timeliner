section	.text
	global ft_putstr

extern ft_strlen

;void	ft_putstr(const char *s)
;Prints null terminated string s to standard output.
;rdi=s
ft_putstr:
	push	rdi
	call	ft_strlen WRT ..plt	;Get string length -> RAX
	mov     rdi, 1		;fd
	pop     rsi			;string
	mov     rdx, rax	;length
	mov     rax, 1		;write
	syscall
	ret
