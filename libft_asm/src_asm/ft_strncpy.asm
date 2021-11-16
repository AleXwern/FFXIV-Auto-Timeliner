section	.text
   global ft_strncpy

;char	*ft_strncpy(char *dst, const char *src, size_t len)
;Destructively copies len characters from src to dst. If len > strlen(src) the fill the remaining area with null bytes.
;rdi=dst		rsi=src		rdx=len
ft_strncpy:
	xor		rcx, rcx
strncpy:
	cmp		byte [rsi + rcx], 0
	jz		bzero
	cmp		rcx, rdx
	jae		bzero
	movzx	eax, byte [rsi + rcx]
	mov		byte [rdi + rcx], al
	inc		rcx
	jmp		strncpy
bzero:
	cmp		rcx, rdx
	jae		bzero
	mov		byte [rdi + rcx], 0
	inc		rcx
	jmp		bzero
return:
	mov		rax, rdi
	ret
