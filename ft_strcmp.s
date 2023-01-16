section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0
	jmp _ft_compare

_ft_compare:
	mov al, [rdi+rcx]
	mov dl, [rsi+rcx]

	cmp al, 0   ;check if rdi[rcx] = '\0'
	je _ft_return			;if true call func ret

	cmp al, dl				;compare rdi[rcx]/dl = rsi[rcx]
	jne _ft_return						;if not the same call func ret

	inc rcx					;increase rcx
	jmp _ft_compare			;jump to ft_compare

_ft_return:
	movzx   rax, al
	movzx   rdx, dl
	sub rax, rdx
	ret
