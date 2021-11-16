section	.text
   global ft_isalnum

;int		ft_isalnum(int c)
;Returns 1 if c represents a character or a number in ascii. Else 0.
;rdi=c
ft_isalnum:
	mov		eax, edi
	and		eax, -33	;The difference between 'A' and 'a' is the 3rd significant bit so we AND that out
	add		eax, -65
	cmp		eax, 26
	setb	al			;Result for letters is stored in AL
	add		edi, -48
	cmp		edi, 10
	setb	cl			;Result for numbers is stored in CL
	or		cl, al
	movzx	eax, cl		;If either AL or AL is 1 we return 1. Else 0
	ret
