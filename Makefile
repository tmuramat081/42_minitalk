NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_SRCS = ./src/client.c ./src/utils.c
SERVER_SRCS = ./src/server.c ./src/utils.c
CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}
SERVER_OBJS = ${SERVER_SRCS:.c=.o}
BONUS_NAME = minitalk_bonus
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_SRCS = ./src/client_main_bonus.c ./src/client_handler_bonus.c ./src/utils_bonus.c
SERVER_BONUS_SRCS = ./src/server_main_bonus.c ./src/server_handler_bonus.c ./src/utils_bonus.c
CLIENT_BONUS_OBJS = ${CLIENT_BONUS_SRCS:.c=.o}
SERVER_BONUS_OBJS = ${SERVER_BONUS_SRCS:.c=.o}
LIBFTDIR = ./libft
LIBFT = ./libft/libft.a
INCS = -I ./includes -I ${LIBFTDIR}
CC = gcc
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${CLIENT_NAME} ${SERVER_NAME}

bonus: ${CLIENT_BONUS_NAME} ${SERVER_BONUS_NAME}

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${CLIENT_NAME}: ${CLIENT_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${CLIENT_OBJS} ${LIBFT} ${INCS} -o $@

${SERVER_NAME}: ${SERVER_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${SERVER_OBJS} ${LIBFT} ${INCS} -o $@

${CLIENT_BONUS_NAME}: ${CLIENT_BONUS_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${CLIENT_BONUS_OBJS} ${LIBFT} ${INCS} -o $@

${SERVER_BONUS_NAME}: ${SERVER_BONUS_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${SERVER_BONUS_OBJS} ${LIBFT} ${INCS} -o $@

.c.o:
	${CC} ${CFLAGS} $< -c ${INCS} -o $@

clean:
	rm -f ${CLIENT_OBJS} ${SERVER_OBJS} ${CLIENT_BONUS_OBJS} ${SERVER_BONUS_OBJS}
	${MAKE} clean -C ${LIBFTDIR}

fclean: clean
	rm -f ${CLIENT_NAME} ${SERVER_NAME} ${CLIENT_BONUS_NAME} ${SERVER_BONUS_NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all bonus clean fclean re kill

kill:
	pgrep server | xargs kill -9