NAME = minitalk
C_NAME = client
S_NAME = server
ifndef BONUS_FLAG
C_NAME = client
S_NAME = server
C_SRCS = ./src/client.c ./src/utils.c
S_SRCS = ./src/server.c ./src/utils.c
else
C_NAME = client_bonus
S_NAME = server_bonus
C_SRCS = ./src/client_bonus.c ./src/utils_bonus.c
S_SRCS = ./src/server_bonus.c ./src/utils_bonus.c
endif
C_OBJS = ${C_SRCS:.c=.o}
S_OBJS = ${S_SRCS:.c=.o}
LIBFT = ./libft/libft.a
INCS = ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror

minitalk: ${C_NAME} ${S_NAME}

all: ${NAME}

bonus:
	@make BONUS_FLAG=1

${LIBFT}:
	make -C libft

${C_NAME}: ${LIBFT} ${C_OBJS}
	${CC} ${CFLAGS} ${C_OBJS} ${LIBFT} -I ${INCS} -o $@

${S_NAME}: ${LIBFT} ${S_OBJS}
	${CC} ${CFLAGS} ${S_OBJS} ${LIBFT} -I ${INCS} -o $@

.c.o:
	${CC} ${CFLAGS} $< -c -I ${INCS} -o ${<:.c=.o}

clean:
	rm -f ${C_OBJS} ${S_OBJS}
	make fclean -C ./libft

fclean: clean
	rm -f ${C_NAME} ${S_NAME}
	make fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re 

#kill:
#	pgrep server | xargs kill -9