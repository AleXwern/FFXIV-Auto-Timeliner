section	.text
   global ft_strlcat

;size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
;Appends max dstsize-strlen(dst)-1 characters to dst from src, overriding the
;terminating null byte and adding new one to end of the new string. 
;User must handle the correct size of dst or buffer overrun causes undefined behaviour.
;Returns the total amount of bytes that would have been copied but not necessarily what was copied.
;rdi=dst		rsi=src		rdx=dstsize
ft_strlcat:
	xor		rax, rax
	xor		r8, r8
srclen:
	cmp		byte [rsi + rax], 0
	jz		dstlen
	inc		rax
	jmp		srclen
dstlen:
	cmp		byte [rdi + r8], 0
	jz		sizecheck
	inc		r8
	jmp		dstlen
sizecheck:
	mov		rcx, rdx
	cmp		rdx, r8
	cmova	rcx, r8
	add		rax, rcx
	mov		r9, r8
	inc		r9
	jmp		check
strlcat_loop:
	movzx	ecx, byte [rsi]
	mov		byte [rdi + r8], cl
	inc		r8
	inc		rsi
	inc		r9
check:
	cmp		r9, rdx
	jae		return
	cmp		byte [rsi], 0
	jz		return
	jmp		strlcat_loop
return:
	mov		byte [rdi + r8], 0
	ret
