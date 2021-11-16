section	.text
	global ft_putendl_fd

extern ft_strlen

;void ft_putendl_fd(const char *s, int fd)
;Writes null terminated string s to specified file descriptor fd followed by a newline.
;rdi=s	rsi=fd
ft_putendl_fd:
	push	rdi
	call	ft_strlen	;Get string length -> RAX
	mov     rdi, rsi	;fd
	pop     rsi			;string
	mov     rdx, rax	;length
	mov     rax, 1		;write
	syscall
	mov		rax, 1
	mov		rsi, endl
	mov		rdx, 1
	syscall
	ret

section .data			;For some reason I couldn't get the addr of variabe with 0xA
	endl	db 0xa,0x0	;so I made a define that's printed instead
