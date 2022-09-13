SRCS	= main.c ft_atoi.c ft_operations.c ft_putnbr.c 

OBJS	= ${SRCS:.c=.o} 

CC	= gcc

RM	= rm -f

PROG	= do-op

CFLAGS	= -Wall -Wextra -Werror 

.c.o:
		@ ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${PROG}:	${OBJS}
		@ ${CC} ${CFLAGS} -o ${PROG} ${OBJS}

all:		${PROG}

clean:
		@ ${RM} ${OBJS}

fclean:		clean
		@ ${RM} ${PROG}

re:		fclean all

.PHONY: all clean fclean re 
