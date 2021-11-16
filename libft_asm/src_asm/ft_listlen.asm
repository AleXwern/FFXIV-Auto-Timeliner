section	.text
   global ft_listlen

;size_t	ft_listlen(char	**list)
;Takes NULL pointer terminated array of pointers and returns the length of the array.
;Expands the functionality of ft_strsplit since I tend to use this a lot.
;rdi=str
ft_listlen:
	xor		rax, rax
	test	rdi, rdi
	jz		return
	jmp		check
listlen_loop:
	inc		rax
	add		rdi, 8
check:
	cmp 	qword [rdi], 0
	jne		listlen_loop
return:
	ret