section	.text
   global ft_intsize

;size_t		ft_intsize(long n)
;Returns the number of digits in integer
;I know there are other ways to do this but this seems the most straightforward for now.
;rdi=n
ft_intsize:
	mov		rcx, 1
	mov		rax, rdi
	mov		rsi, 10
	test	rax, rax
	jns		intloop
	inc		rcx
	neg		rax
intloop:
	cmp		rax, 9
	jbe		return
	xor		rdx, rdx	;EDX needs to bl cleared or I get "Floating point exception"
	idiv	rsi
	inc		rcx
	jmp		intloop
return:
	mov		rax, rcx
	ret
