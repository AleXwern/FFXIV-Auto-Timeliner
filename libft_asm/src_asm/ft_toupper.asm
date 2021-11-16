section	.text
   global ft_toupper

;int		ft_toupper(int c)
;Checks if c represents any ASCII character from 'a' (97) to 'z' (122) and returns the uppercase version.
;rdi=c
ft_toupper:
	mov		eax, edi
	lea		ecx, [edi-97]
	lea		edx, [edi-32]
	cmp		ecx, 26
	cmovb	eax, edx
	ret
