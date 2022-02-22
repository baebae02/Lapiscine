/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:59:29 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/06 13:33:51 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_three(int k, int i, int j)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = '0' + k;
	n2 = '0' + i;
	n3 = '0' + j;
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
	if (k != 7)
	{	
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < 8)
	{
		i = k + 1;
		while (i < 9)
		{
			j = i + 1;
			while (j < 10)
			{
				ft_putnbr_three(k, i, j);
				j++;
			}
			i++;
		}
		k++;
	}
}
