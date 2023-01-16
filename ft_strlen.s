section .text
global _ft_strlen

_ft_strlen:
	mov rax, 0
	jmp _ft_checklength

_ft_checklength:
	cmp BYTE rdi[rax], 0
	je _ret
	inc rax
	jmp _ft_checklength

_ret:
	ret