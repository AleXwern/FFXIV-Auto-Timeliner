section	.text
	global ft_strdup

extern malloc
extern ft_strlen

;char	*ft_strdup(const char *s1)
;Allocates new pointer and copies over null terminated string s1 to it.
;rdi=s1
ft_strdup:
	push	rdi
	call	ft_strlen
	mov		rdi, rax
	call	malloc
	pop		rdi
	xor		rcx, rcx
strdup_loop:
	movzx	esi, byte [rdi + rcx]
	mov		byte [rax + rcx], sil
	inc		rcx
	test	sil, sil
	jnz		strdup_loop
return:
	ret
