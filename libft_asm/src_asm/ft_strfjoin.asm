section	.text
	global ft_strfjoin

extern malloc
extern free
extern ft_strlen

;char	*ft_strfjoin(char *s1, char *s2)
;Takes null terminated strings s1 and s2, allocates new strlen(s1+s2)+1 length pointer,
;copies both of them to it and returns the pointer to it.
;In addition strfjoin also attempts to free s1 and if s1 is not malloced pointer then
;program is likely to crash.
;rdi=s1	rsi=s2
ft_strfjoin:
	push	rdi
	push	rsi
	mov		r8, 1		;initialize at 1 for null byte
	call	ft_strlen	;All these ft_strlen calls return length of string to RAX which we add to R8 which is the total length.
	add		r8, rax
	mov		rdi, rsi
	call	ft_strlen
	add		r8, rax
	mov		rdi, r8
	call	malloc		;RAX=buffer, R8=legth of combined string
	pop		rsi
	pop		rdi
	xor		r9, r9
	xor		rcx, rcx
s1:						;Loop and combine all strings to target (RAX). It's a lot of repetition but I d'm not sure how to condense it.
	movzx	r10d, byte [rdi + rcx]
	test	r10b, r10b
	jz		s2
	mov		byte [rax + r9], r10b
	inc		r9
	inc		rcx
	jmp		s1
s2:
	movzx	r10d, byte [rsi]
	mov		byte [rax + r9], r10b
	inc		r9
	inc		rsi
	test	r10b, r10b
	jnz		s2
return:
	push	rax
	call	free
	pop		rax	
	ret
