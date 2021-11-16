section	.text
   global ft_tolower

;int		ft_tolower(int c)
;Checks if c represents any ASCII character from 'A' (65) to 'Z' (90) and returns the lowercase version.
;rdi=c
ft_tolower:
	mov		eax, edi
	lea		ecx, [edi-65]
	lea		edx, [edi+32]
	cmp		ecx, 26
	cmovb	eax, edx
	ret
