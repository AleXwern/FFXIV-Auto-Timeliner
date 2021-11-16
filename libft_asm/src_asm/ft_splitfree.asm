section	.text
	global ft_splitfree

extern free

;void	ft_splitfree(char **c)
;Takes null pointer terminated array of pointers and frees all pointers in it
;as well as the base list.
;Inteded to free arrays created by ft_strsplit.
;rdi=c
ft_splitfree:
	mov		r13, rdi
	xor		r14, r14
	test	r13, r13
	jz		return
freeloop:
	cmp		qword [r13 + r14], 0
	jz		freebase
	mov		rdi, qword [r13 + r14]
	call	free
	add		r14, 8
	jmp		freeloop
freebase:
	mov		rdi, r13
	call	free
return:
	ret
