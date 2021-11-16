section	.text
   global hello     ;must be declared for linker (ld)
	
hello:	            ;tells linker entry point
	push rdi
	mov	rdx,5     ;message length
	pop	rcx     ;message to write
	mov	rbx,1       ;file descriptor (stdout)
	mov	rax,4       ;system call number (sys_write)
	int	0x80        ;call kernel
	
	mov	rax,1       ;system call number (sys_exit)
	int	0x80        ;call kernel

section	.data
	msg db 'Hello, world!', 0xa  ;string to be printed
	len equ $ - msg     ;length of the string