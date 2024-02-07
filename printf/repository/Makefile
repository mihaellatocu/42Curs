NAME = libftprintf.a

CFLAGS= -Wall -Wextra -Werror
CC= cc

all: $(NAME)

$(NAME) : ft_printf.o ft_strings.o
	ar -r $(NAME) ft_printf.o ft_strings.o

ft_printf.o : ft_printf.c ft_strings.c
	$(CC) $(CFLAGS) -c ft_printf.c ft_strings.c

clean:
	rm -f ft_printf.o ft_strings.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clear fclean re
