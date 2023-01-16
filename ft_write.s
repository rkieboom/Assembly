section .text
	global _ft_write
	extern ___error

_ft_write:
	mov rax, 0x2000004
	syscall
	jc _error
	ret

_error:
	push rbp ; stack alignment
	mov rdx, rax;
    call ___error
	mov [rax], rdx ; *rax = rcx
    pop rbp
	mov rax, -1
	ret