NAME = libftprintf.a

MY_SOURCES =	ft_printf.c ft_printf_di.c ft_printf_s.c ft_printf_xx.c \
   	  ft_putchar.c ft_putstr.c ft_printf_p.c ft_printf_u.c \
 	  ft_printf_c.c ft_putnbr.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rc $(NAME) $(MY_OBJECTS)

%.o:	%.c
	gcc ${CFLAGS} -I . -c $< -o $@

clean:
	rm -rf $(MY_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re