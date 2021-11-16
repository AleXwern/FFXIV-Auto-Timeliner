section	.text
	global ft_quadjoin

extern malloc
extern ft_strlen

;char	*ft_quadjoin(char *s1, char *s2, char *s3, char *s4)
;Extnsion of ft_strjoin but takes 4 null termated strings.
;Allocates new area with size of combined length of all 4 strings plus 1 byte for
;terminating null byte.
;rdi=s1	rsi=s2	rdx=s3	rcx=s4
ft_quadjoin:
	push	rdi
	push	rsi
	push	rdx
	push	rcx
	mov		r8, 1		;initialize at 1 for null byte
	call	ft_strlen	;All these ft_strlen calls return length of string to RAX which we add to R8 which is the total length.
	add		r8, rax
	mov		rdi, rsi
	call	ft_strlen
	add		r8, rax
	mov		rdi, rdx
	call	ft_strlen
	add		r8, rax
	mov		rdi, rcx
	call	ft_strlen
	add		r8, rax
	mov		rdi, r8
	call	malloc		;RAX=buffer, R8=legth of combined string
	pop		rcx			;So many push/pops but I was losing my data on malloc call
	pop		rdx
	pop		rsi
	pop		rdi
	xor		r9, r9
s1:						;Loop and combine all strings to target (RAX). It's a lot of repetition but I d'm not sure how to condense it.
	movzx	r10d, byte [rdi]
	test	r10b, r10b
	jz		s2
	mov		byte [rax + r9], r10b
	inc		r9
	inc		rdi
	jmp		s1
s2:
	movzx	r10d, byte [rsi]
	test	r10b, r10b
	jz		s3
	mov		byte [rax + r9], r10b
	inc		r9
	inc		rsi
	jmp		s2
s3:
	movzx	r10d, byte [rdx]
	test	r10b, r10b
	jz		s4
	mov		byte [rax + r9], r10b
	inc		r9
	inc		rdx
	jmp		s3
s4:
	movzx	r10d, byte [rcx]
	mov		byte [rax + r9], r10b
	inc		r9
	inc		rcx
	test	r10b, r10b
	jnz		s4
return:
	ret
