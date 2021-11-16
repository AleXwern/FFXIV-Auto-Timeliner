extern ft_strlen
section	.text
   global ft_strcat

;char	*ft_strcat(char *dest, const char *src)
;Appends src to the end of dest, overriding \0 byte. Strings may not overlap and dest
;must have enough space for src.
;Use of strncat or strjoin (if memory is managed) are recommened.
;rdi=dest	rsi=src
ft_strcat:
	call	ft_strlen		;dest is already in rdi, get len in rax
	mov		rcx, rax
	mov		rax, rdi
	test	rax, rax
	jz		return
strcat_copy:
	mov		dl, byte [rsi]
	mov		byte [rdi + rcx], dl
	cmp		byte [rsi], 0
	jz		return
	add		rcx, 1
	add		rsi, 1
	jmp		strcat_copy
return:
	ret
