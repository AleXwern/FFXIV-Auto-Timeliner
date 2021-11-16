; mmap
mov r8, rax           ; rax holds opened file descriptor
                      ; it is the fourth argument of mmap
mov rax, 9            ; mmap number
mov rdi, 0            ; operating system will choose mapping destination
mov rsi, 4096         ; page size
mov rdx, PROT_READ    ; new memory region will be marked read only
mov r10, MAP_PRIVATE  ; pages will not be shared
                      
mov r9, 0             ; offset inside test.txt
syscall               ; now rax will point to mapped location 

mov rdi, rax
call print_string

mov rax, 60           ; use exit system call to shut down correctly
xor rdi, rdi
syscall