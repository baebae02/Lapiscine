/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:52:56 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/08 14:45:25 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	if (c >= ' ' && c != 127)
		return (1);
	else
		return (-1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	current;

	i = 0;
	while (str[i] != '\0')
	{
		current = str[i];
		if (current == '\0')
			break ;
		if (is_printable(current) > 0)
			ft_putchar(current);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[current / 16]);
			ft_putchar("0123456789abcdef"[current % 16]);
		}
		i++;
	}
}	
