/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:54:44 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/07 16:37:08 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_arr[10];

void	ft_putint(int n)
{
	char	a;

	a = g_arr[n] + '0';
	write(1, &a, 1);
}

void	ft_putcomma(int M)
{
	if (g_arr[0] != 10 - M)
	{
		write(1, ", ", 2);
	}
}

#include <stdio.h>
void	ft_back_track(int x, int current_len, int len)
{
	printf("\nBACKTRACKING : %d, %d, %d\n", x, current_len, len);
	int	j;
	int	i;

	if (current_len == len)
	{	
		i = 0;
		while (i < len)
		{
			ft_putint(i);
			i++;
		}
		ft_putcomma(len);
		return ;
	}
	j = x;
	while (j <= 9)
	{	
		printf("\nx is %d, c_l is %d, j is %d\n", x, current_len, j);
		g_arr[current_len] = j;
		ft_back_track(j + 1, current_len + 1, len);
		j++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	ft_back_track(0, 0, n);
}

int main(void)
{
	ft_print_combn(2);
}
