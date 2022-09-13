SRCS	= ${S_PATH}ft_putchar.c ${S_PATH}ft_swap.c ${S_PATH}ft_putstr.c ${S_PATH}ft_strlen.c ${S_PATH}ft_strcmp.c
S_PATH	= ./srcs/
INCLUDE	= ./includes/

OBJS	= ${SRCS:.c=.o} 

LIB	= libft.a

CC	= gcc

ARRC	= ar rc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -I ${INCLUDE}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:		${OBJS}
		${ARRC} -o ${LIB} ${OBJS}

all:		${LIB}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${LIB}

re:		fclean all

.PHONY: all clean fcleain re 
