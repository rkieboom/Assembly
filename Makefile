RM = rm -f
LIB = ar rcs
CC = gcc
CCFLAGS = -g -Wall -Wextra -fomit-frame-pointer
NASM = nasm
NASMFLAGS = -f macho64
NAME = libasm.a
ASMSRC = ft_strlen.s ft_strcpy.s ft_write.s ft_read.s ft_strcmp.s ft_strdup.s
ASMOBJ = $(ASMSRC:.s=.o)

all: $(NAME)

$(NAME): $(ASMOBJ)
	$(LIB) $(NAME) $(ASMOBJ)

test: re
	$(CC) main.c $(NAME)

%.o: %.s
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	$(RM) $(ASMOBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all
