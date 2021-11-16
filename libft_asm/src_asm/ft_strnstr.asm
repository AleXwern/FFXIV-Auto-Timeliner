section	.text
   global ft_strnstr

;char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
;Searches string "needle" from "haystack" and returns pointer to the first character of needle
;found in haystack if the entire string is found, else returns null.
;limits the search to len characters. The last character of needle must be within the len bytes
;rdi=haystack		rsi=needle		rdx=len
ft_strnstr:
	xor		rcx, rcx				;general index
	xor		rax, rax
	cmp		byte [rsi], 0			;if sub-string is empty, return haystack as-is
	jz		return
	movzx	r8, byte [rsi]			;r8 has the 1st character of sub-string because we cannot dereference 2 registers in single instruction
strnstr_loop:
	cmp 	byte [rdi + rcx], 0
	jz		return
	cmp		rcx, rdx
	jae		return
	cmp		byte [rdi + rcx], r8b	;if any character within haystack is same as 1st of needle, eneter sub-loop
	je		needle
increment:							;This is here so I can jump back to it
	inc		rcx
	jmp		strnstr_loop
setptr:								;jump here if correct sub-string was found, else jump to return
	lea		rax, [rdi + rcx]
return:
	ret

needle:								;Nested loop detached like this for readability... for now
	mov		r9, 1					;needle pos
	mov		r10, rcx
	inc		r10						;needle pos + general index
needle_loop:
	movzx	r11, byte [rsi + r9]
	cmp		r11b, 0
	je		setptr					;If we meet the needle null, go straight to return condition
	cmp		r11b, byte [rdi + r10]
	jne		increment				;if bytes differ or we go OOB, exit sub-loop
	cmp		r10, rdx
	jae		increment
	inc		r9
	inc		r10
	jmp		needle_loop
