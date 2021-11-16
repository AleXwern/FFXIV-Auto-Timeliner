section	.text
   global ft_strtrim

extern	ft_strlen
extern	ft_strsub

;char	*ft_strtrim(char const *s)
;Trims leading and trailing whitespaces, linefeeds and tabulations from the string.
;Allocates and creates new null terminated string where the resulting string is stored.
;rdi=s
ft_strtrim:
	test	rdi, rdi
	jz		.retnull
	mov		rsi, rdi
	call	ft_strlen
	xor		rcx, rcx
;rax=len rcx=leading rsi=s
.lead:
	movzx	edx, byte [rsi+rcx]
	cmp		dl, 9
	je		.inc1
	cmp		dl, 10
	je		.inc1
	cmp		dl, 32
	je		.inc1
	jmp		.tail
.inc1:
	test	dl, dl
	jz		.tail
	inc		rcx
	jmp		.lead
.tail:
	movzx	edx, byte [rsi+rax-1]
	cmp		dl, 9
	je		.inc2
	cmp		dl, 10
	je		.inc2
	cmp		dl, 32
	je		.inc2
	jmp		.ret
.inc2:
	cmp		rax, rcx
	jbe		.ret
	dec		rax
	jmp		.tail
.ret:
	mov		rdi, rsi
	mov		rsi, rcx
	mov		rdx, rax
	sub		rdx, rsi
	call	ft_strsub
	ret
.retnull:
	mov		rax, rdi
	ret