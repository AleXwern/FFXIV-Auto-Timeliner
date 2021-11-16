default rel

section	.text
   global ft_puthexln

;void		ft_puthexln(unsigned long num)
;Writes hex presentation of maximum of 64-bits wide integer to standard output
;followed by a newline.
;rdi=num
ft_puthexln:
	mov		rcx, 19
	sub		rsp, 40
	mov		byte [rsp + 20], 10
.hexloop:
	mov		rsi, rdi
	and		rsi, 15
;	movzx	eax, byte [rel hex + rsi]	;This is removed for shared objects for now
	cmp		sil, 9
	ja		.hex
	add		sil, 48
	jmp		.comp
.hex:
	add		sil, 55
.comp:
	mov		byte [rsp + rcx], sil
	shr		rdi, 4
	dec		rcx
	cmp		rdi, 0
	ja		.hexloop
;write	
	mov		rdx, 20				;len
	sub		rdx, rcx
	inc		rcx
	lea		rsi, [rsp + rcx]	;string
	mov		rdi, 1				;fd
	mov		rax, 1				;write
	syscall
	add		rsp, 40
	ret

;For some reason I can't get data or rodata to behave with SOs so I'll do very hacky
;version for now.
;section .rodata
;	hex	db "0123456789abcdef"
