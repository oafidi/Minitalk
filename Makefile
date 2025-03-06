CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SERVER_NAME = server
SERVER_BONUS_NAME = server_bonus

CLIENT_NAME = client
CLIENT_BONUS_NAME = client_bonus

CLIENT_SRC = mandatory/client.c  tools/helper_functions/ft_atoi.c
MANDATORY_HEADER = mandatory/minitalk.h
SERVER_SRC = mandatory/server.c tools/helper_functions/ft_set_client.c

CLIENT_BONUS_SRC = bonus/client_bonus.c  tools/helper_functions_bonus/ft_atoi_bonus.c
MANDATORY_BONUS_HEADER = bonus/minitalk_bonus.h
SERVER_BONUS_SRC = bonus/server_bonus.c tools/helper_functions_bonus/ft_set_client_bonus.c tools/helper_functions_bonus/ft_memset.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

PRINTF_PATH = tools/printf
PRINTF_A = tools/printf/libftprintf.a

PRINTF_SRC = tools/printf/charformat.c tools/printf/check_next.c tools/printf/ft_printf.c tools/printf/ft_puthexa.c \
	tools/printf/ft_putnbr.c tools/printf/ft_putunsigned.c tools/printf/hexaformat.c tools/printf/intformat.c \
	tools/printf/pointerformat.c tools/printf/stringformat.c tools/printf/unsignedformat.c tools/printf/ft_printf.h

all: $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

$(PRINTF_A): $(PRINTF_SRC)
	make -C $(PRINTF_PATH)

$(SERVER_NAME): $(SERVER_OBJ) $(PRINTF_A)
	$(CC) $(CFLAGS) $(PRINTF_A) $(SERVER_OBJ) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(PRINTF_A) $(MANDATORY_HEADER)
	$(CC) $(CFLAGS) $(PRINTF_A) $(CLIENT_OBJ) -o $(CLIENT_NAME)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJ) $(PRINTF_A) $(MANDATORY_BONUS_HEADER)
	$(CC) $(CFLAGS) $(PRINTF_A) $(SERVER_BONUS_OBJ) -o $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJ) $(PRINTF_A) $(MANDATORY_BONUS_HEADER)
	$(CC) $(CFLAGS) $(PRINTF_A) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS_NAME)

mandatory/%.o:mandatory/%.c $(MANDATORY_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

tools/helper_functions/%.o:tools/helper_functions/%.c $(MANDATORY_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

tools/helper_functions_bonus/%.o:tools/helper_functions_bonus/%.c $(MANDATORY_BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o:bonus/%.c $(MANDATORY_BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(PRINTF_PATH)
	$(RM) $(CLIENT_OBJ)
	$(RM) $(SERVER_OBJ)
	$(RM) $(CLIENT_BONUS_OBJ)
	$(RM) $(SERVER_BONUS_OBJ)

fclean: clean
	make fclean -C $(PRINTF_PATH)
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_BONUS_NAME)
	$(RM) $(CLIENT_BONUS_NAME)

re: fclean all
