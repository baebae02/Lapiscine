# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:23:37 by seohbae           #+#    #+#              #
#    Updated: 2022/02/22 17:18:05 by seohbae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

INCDIR = includes 
SRCDIR = srcs

NAME = libft.a
SRCS = ${SRCDIR}/ft_putchar.c ${SRCDIR}/ft_putstr.c ${SRCDIR}/ft_strlen.c ${SRCDIR}/ft_strcmp.c ${SRCDIR}/ft_swap.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCDIR}

${NAME}: ${OBJS}
	ar rc $@ ${OBJS}
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:
	fclean all

.PHONY: all clean fclean re