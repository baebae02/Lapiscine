# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 15:32:22 by seohbae           #+#    #+#              #
#    Updated: 2022/02/23 14:27:44 by seohbae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_atoi.c srcs/ft_doop.c srcs/ft_putnbr.c srcs/ft_calculate.c
OBJS	= ${SRCS:.c=.o}
NAME	= do-op
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all