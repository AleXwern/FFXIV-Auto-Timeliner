section	.text
	global ft_strdel

extern free

;void	ft_strdel(char **ap)
;Receives pointer to pointer that should be freed and protectively frees it (for legacy reasons)
;Also sets the freed pointer to NULL.
;As far as assembly goes this is exactly the same as ft_memdel.
;rdi=ap
ft_strdel:
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
