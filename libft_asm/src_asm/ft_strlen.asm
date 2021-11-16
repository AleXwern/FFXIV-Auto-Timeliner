section	.text
	global ft_strlen

;size_t		ft_strlen(const char *str)
;Receives null terminated string str and returns the length of the string.
;rdi=str
ft_strlen:
	mov		rax, rdi
getchar:	;Compare character to 0 to see if we are at end. If 0 jump to return.
	cmp		byte [rax], 0
	jz		done
	inc		rax
	jmp		getchar
done:		;We get return value by subtracting the offset value by the original value
	sub		rax, rdi
	ret
