# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:23:40 by seohbae           #+#    #+#              #
#    Updated: 2022/02/21 17:23:41 by seohbae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a
gcc -c -Wall -Wall -Wextra ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
ar -rcs libft.a *.o
rm -f *.o