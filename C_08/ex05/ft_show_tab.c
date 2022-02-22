/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:24:23 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/19 11:34:30 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#include "ft_stock_str.h"

void	ft_putsize(int	n)
{
	if (n > 9)
		ft_putsize(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putsize(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
