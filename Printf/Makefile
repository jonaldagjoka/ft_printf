NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS =  ft_printf.c \
        ft_print_pointer.c \
        ft_print_unsigned.c \
        ft_print_string.c \
        ft_print_decimal.c \
        ft_print_char.c \
        ft_print_hex.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re