section	.text
   global ft_memccpy

;void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
;memccpy copies exactly n bytes from src to dst or stops if character c is found.
;It also returns a pointer to the next character in dst after c was found or null if it wasn't.
;In a sense it's a combination of memcpy and memchr.
;rdi=dst	rsi=src 	rdx=c	rcx=n
ft_memccpy: 
	xor		r8, r8					;counter to n
	xor		rax, rax
memccpy_loop:
	cmp		rcx, r8
	je		return
	movzx	r9, byte [rsi + r8]		;I can't move from array to array so I quess I'll go with this.
	mov		byte [rdi + r8], r9b
	inc		r8						;Increase counter by 1 before maybe jumping. i++ before next loop or return the character after c.
	cmp		r9, rdx					;Check for character
	jne		memccpy_loop
	add		rdi, r8					;If character was found we return the relative pointer
	mov		rax, rdi
return:
	ret
