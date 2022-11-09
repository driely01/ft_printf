SRC = ft_printf.c helpers.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all