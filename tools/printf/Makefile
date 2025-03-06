CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

AR = ar -rcs

RM = rm -f

SRC = charformat.c check_next.c ft_printf.c ft_puthexa.c ft_putnbr.c ft_putunsigned.c hexaformat.c intformat.c \
	pointerformat.c stringformat.c unsignedformat.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $?

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re: fclean all
