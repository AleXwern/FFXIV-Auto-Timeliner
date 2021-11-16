section	.text
	global ft_memdel

extern free

;void	ft_memdel(void **ap)
;Receives pointer to pointer that should be freed and protectively frees it (for legacy reasons)
;Also sets the freed pointer to NULL.
;rdi=ap
ft_memdel:
	test	rdi, rdi
	jz		return
	mov		rax, qword [rdi]
	test	rax, rax
	jz		return
	push	rdi
	mov		rdi, rax
	call	free
	pop		rdi
	mov		qword [rdi], 0
return:
	ret
