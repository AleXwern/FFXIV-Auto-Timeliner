section	.text
	global ft_putstr_fd

extern ft_strlen

;void	ft_putstr_fd(const char *s, int fd)
;Prints null terminated string s to set output.
;rdi=s	rsi=fd
ft_putstr_fd:
	push	rdi
	call	ft_strlen WRT ..plt	;Get string length -> RAX
	mov     rdi, rsi			;fd
	pop     rsi					;string
	mov     rdx, rax			;length
	mov     rax, 1				;write
	syscall
	ret
