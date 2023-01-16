section .text
global _ft_strcpy

_ft_strcpy:
	mov rcx, 0				;Set rcx to 0
	jmp _ft_copy			;Goto ft_copy

_ft_copy:
	cmp BYTE [rsi+rcx], 0		;Compare rsi[rcx] = 0 Second argument
	mov dl, BYTE [rsi+rcx]		;Copy dl = rsi+rcx
	mov BYTE [rdi+rcx], dl		;Copy rdi[rcx] = dl
	je _ret						;Exit if compare = 0
	inc rcx						;Increment rcx
	jmp _ft_copy				;Goto ft_copy

_ret:
	mov rax, rdi
	ret