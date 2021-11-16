section	.text
   global ft_striteri

;void	ft_striteri(char *s, void (*f)(unsigned int, char *))
;Performs function f to each character/substring s.
;Also sends an unsigned integer to function f which represents Nth count in loop
;where first one is 0 (aka index of the current character)
;rdi=s		rsi=(*f)(unsigned int, char *))
ft_striteri:
	test	rdi, rdi
	jz		return
	test	rsi, rsi
	jz		return
	cmp		byte [rdi], 0		;Check NULLs and if the first character is not \0
	jz		return
	push	r12
	mov		r12, rsi			;move f to r12 because it's preserved
	mov		r13, rdi			;make a copy of char pointer s
	xor		r14, r14			;create original index
striteri_loop:
	mov		edi, r14d			;copy s and index to parameter slots
	mov		rsi, r13
	call	r12					;call function pointer
	inc		r13					;increment original values
	inc		r14d
	cmp		byte [r13], 0
	jnz		striteri_loop
	pop		r12
return:
	ret
