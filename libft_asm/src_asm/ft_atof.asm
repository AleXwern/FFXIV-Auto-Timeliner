section	.text
   global ft_atof

extern ft_isblank

;double		ft_atof(const char *str)
;Takes a string presentation of a floating point value and returns a real floating point value.
;I have 2 implementations of this and so far it's justtesting if either have any errors.
;"integer-multiply" gives very wrong numbers if fractional part has too many numbers.
;"fpn-multiply" might have some precicion errors but I have not found any... yet.
;rdi=str
ft_atof:
	push	rbx				;We want couple values to persist so we push RBX/RBP to stack and store the values on those regs
	push	rbp
	test	rdi, rdi
	jz		return
	mov		rbx, rdi		;String on RDI
	jmp		blanks
skip:						;Filter out blank characters from start
	inc		rbx
blanks:
	movzx	edi, byte [rbx]
	call	ft_isblank
	test	eax, eax
	jnz		skip			;If all blanks are filtered, init values else continue loop
	pxor	xmm0, xmm0		;Init start value to 0
	mov		rbp, 1			;Sign
	movzx	eax, byte [rbx]
	cmp		eax, 45
	jne		signcheck		;If byte is 45='-', set sign to -1
	mov		rbp, -1			;Default sign is positive, but in case of negative it's changed to -1
signcheck:
	sub		eax, 43			;If there is '+' or '-' skip over them
	test	al, -3
	jne		isrange
	inc		rbx
	jmp		isrange
atof_loop:					;This all is basically value = value * 10 + (current char number)
	sub		eax, 48
	mulsd	xmm0, [ten]
	pxor	xmm2, xmm2
	cvtsi2sd	xmm2, rax
	addsd	xmm0, xmm2
	inc		rbx
isrange:					;Check if next character is 0-9 or if it's a '.'
	movzx	eax, byte [rbx]
	lea		edx, [eax-48]
	cmp		dl, 9
	jbe		atof_loop
	cmp		eax, 46			;Chesk if byte is '.'. If is we have to get numvers past point
	jne		return
fraction:
	mov		rdi, rbx
	call	atof_fractal
return:						;Multiply the value by sign so it ends up negative or positive and return
	cvtsi2sd	xmm1, rbp
	pop		rbp
	pop		rbx
	mulsd	xmm0, xmm1
	ret

;rdi=str	xmm0=num
atof_fractal:
	inc		rdi
	movsd	xmm2, [pone]	;position multiplier
	jmp		frange
floop:
	pxor	xmm3, xmm3
	cvtsi2sd	xmm3, eax	;Convert current value to FP number and put it on correct position
	mulsd	xmm3, xmm2
	addsd	xmm0, xmm3
	mulsd	xmm2, [pone]	;Move next number's position right by 1
	inc		rdi
frange:						;Check that next value is 0-9
	movzx	eax, byte [rdi]
	sub		eax, 48
	cmp		al, 9
	jbe		floop
	ret

section .data
	one		DQ 1.0
	neq		DQ -1.0
	ten		DQ 10.0
	pone	DQ 0.1
