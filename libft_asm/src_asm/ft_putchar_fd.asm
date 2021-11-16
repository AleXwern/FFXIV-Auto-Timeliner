section	.text
   global ft_putchar_fd

;void	ft_putchar_fd(char c, int fd)
;Writes a single character c to specified file descriptor.
;rdi=c	 rsi=fd
ft_putchar_fd:
	sub		rsp, 1
	mov		byte [rsp], dil
	mov		rdi, rsi
	mov		rsi, rsp
	mov		rdx, 1
	mov		rax, 1
	syscall
	add		rsp, 1
	ret
