section	.text
   global ft_puthex

;void		ft_puthex(unsigned long num)
;Writes hex presentation of maximum of 64-bits wide integer to standard output
;rdi=num
ft_puthex:
	mov		rcx, 19
	sub		rsp, 40
hexloop:
	mov		rsi, rdi
	and		rsi, 15
	movzx	eax, byte [hex + rsi]
	mov		byte [rsp + rcx], al
	shr		rdi, 4
	dec		rcx
	cmp		rdi, 0
	ja		hexloop
;write	
	inc		rcx
	mov		rdx, 20				;len
	sub		rdx, rcx
	lea		rsi, [rsp + rcx]	;string
	mov		rdi, 1				;fd
	mov		rax, 1				;write
	syscall
	add		rsp, 40
	ret

section .data
	hex	db "0123456789abcdef"
