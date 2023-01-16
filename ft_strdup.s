section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	call _ft_strlen ;Check strlength of rdi --- ret = rax
	push rdi
	mov rdi, rax	;put return of strlen in rdi
	call _malloc
	cmp rax, 0
	je _ft_error
	pop rdi
	mov rsi, rdi
	mov rdi, rax
	call _ft_strcpy
	ret

_ft_error:
	ret