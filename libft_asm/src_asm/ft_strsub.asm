section	.text
   global ft_strsub

extern malloc

;char	*ft_strsub(char const *s, unsigned int start, size_t len)
;Allocates memory and copies len bytes from s to newly allocated space starting from
;s+start and adding terminating null byte. Returns newly created string.
;If string ends before len bytes are moved, fills the rest of the area with zeroes.
;rdi=s		rsi=start		rdx=len
ft_strsub:
	push	rdi
	push	rsi
	mov		rdi, rdx
	inc		rdi
	push	rdx
	call	malloc
	pop		rdx
	pop		rsi
	pop		rdi
	test	rax, rax
	jz		.return
	xor		rcx, rcx
.strcopy:
	cmp		rcx, rdx
	je		.zerofill
	cmp		byte [rdi + rsi], 0
	jz		.zerofill
	mov		r8b, byte [rdi + rsi]
	mov		byte [rax + rcx], r8b
	inc		rsi
	inc		rcx
	jmp		.strcopy
.zerofill:
	cmp		rcx, rdx
	ja		.return
	mov		byte [rax + rcx], 0
	inc		rcx
	jmp		.zerofill
.return:
	ret
