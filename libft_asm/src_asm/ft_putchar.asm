section	.text
   global ft_putchar

;void	ft_putchar(char c)
;Writes a single character c to standard output.
;rdi=c
ft_putchar:
	sub		rsp, 1
	mov		byte [rsp], dil
	mov		rdi, 1
	mov		rsi, rsp
	mov		rdx, 1
	mov		rax, 1
	syscall
	add		rsp, 1
	ret
