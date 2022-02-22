/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:59:19 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/07 11:00:50 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_put_int(int n)
{
	char	ch;

	ch = n + '0';
	write(1, &ch, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_put_int(i / 10);
			ft_put_int(i % 10);
			write(1, " ", 1);
			ft_put_int(j / 10);
			ft_put_int(j % 10);
			if (i != 98 || j != 99)
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
