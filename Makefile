NAME = fractol
 
SRCS = $(wildcard *.c)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK = -lm -lX11 -lXext
OBJ = $(SRCS:.c=.o)
LIBFT_DIR = libft
PRINTF_DIR = printf
MINI_DIR = minilibx
LIBMLX_LINUX = $(MINI_DIR)/libmlx_Linux.a
# LIBMLX = $(MINI_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(LIBMLX_LINUX)
	$(CC) $(OBJ) -o $(NAME) $(LIBMLX_LINUX) $(LIBFT) $(PRINTF) $(LINK)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBMLX_LINUX):
	make -C $(MINI_DIR)

# $(LIBMLX):
# 	make -C $(MINI_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MINI_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(MINI_DIR)

re: fclean all

.PHONY: all clean fclean re
