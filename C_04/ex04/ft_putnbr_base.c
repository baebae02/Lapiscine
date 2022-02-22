/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:28:07 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/16 17:14:38 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <unistd.h>

bool	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (false);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (false);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (false);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_check_len(char *base)
{
	int	len;

	len = 0;
	while (*base != '\0')
	{
		len++;
		base++;
	}
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_recur(int nbr, char *base, int len)
{
	if (nbr == -2147483648)
	{
		ft_putnbr_recur(nbr / len, base, len);
		write(1, &(base[-(nbr % len)]), 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_recur(-nbr, base, len);
		return ;
	}
	if (nbr >= len)
		ft_putnbr_recur(nbr / len, base, len);
	write(1, &(base[nbr % len]), 1);
}

void	ft_putnbr_base(int	nbr, char *base)
{	
	int	len;

	len = 0;
	if (!ft_check_base(base))
		return ;
	len = ft_check_len(base);
	ft_putnbr_recur(nbr, base, len);
}
