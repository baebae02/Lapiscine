/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:32:42 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/23 16:47:27 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_operator_check(char *argv, char operators[5])
{
	int	i;

	i = 0;
	if (argv[1] != '\0')
	{
		write(1, "0\n", 2);
		return (-1);
	}
	while (i < 5)
	{
		if (*argv == operators[i])
			return (i);
		i++;
	}
	write(1, "0\n", 2);
	return (-1);
}

void	ft_calculate(int n1, int opr, int n2)
{
	int			result;
	static	int	(*operations[5])(int, int) = {
		&ft_add, &ft_minus, &ft_div, &ft_multi, &ft_modul
	};

	if ((opr == 2 || opr == 4) && n2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	result = (operations[opr])(n1, n2);
	ft_putnbr(result);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		n1;
	int		n2;
	int		opr;
	char	operators[5];

	operators[0] = '+';
	operators[1] = '-';
	operators[2] = '/';
	operators[3] = '*';
	operators[4] = '%';
	n1 = 0;
	n2 = 0;
	if (argc == 4)
	{
		opr = ft_operator_check(argv[2], operators);
		if (opr < 0)
			return (0);
		n1 = ft_atoi(argv[1]);
		n2 = ft_atoi(argv[3]);
		ft_calculate(n1, opr, n2);
	}
	return (0);
}
