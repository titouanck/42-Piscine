PATH_SRCS = ./srcs/

SRCS = ${PATH_SRCS}main.c ${PATH_SRCS}algorithm.c ${PATH_SRCS}check_file.c ${PATH_SRCS}conversions.c ${PATH_SRCS}ft_atoi.c ${PATH_SRCS}ft_basics.c ${PATH_SRCS}ft_split.c ${PATH_SRCS}recup_tab.c

OBJS = ${SRCS:.c=.o}

CC = gcc

NAME = bsq

CFLAGS = -Wall -Werror -Wextra -I ${INCLUDE}

INCLUDE = ./includes

.c.o :
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}


${NAME}:	${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS} .user_input

fclean: clean
	rm -f ${NAME}

re:  fclean all;

.PHONY: all clean fclean re