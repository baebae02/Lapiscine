/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:15:01 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/21 14:12:46 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\v')
		return (true);
	if (c == '\n' || c == '\r' || c == '\t')
		return (true);
	return (false);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

bool	ft_base_check(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	temp = str;
	if (str[0] == '\0' || str[1] == '\0')
		return (false);
	while (*temp)
	{
		if (*temp == '+' || *temp == '-' || is_space(*temp))
			return (false);
		temp++;
	}
	while (i < temp - str)
	{
		j = i + 1;
		while (j < temp - str)
		{
			if (str[i] == str[j++])
				return (false);
		}
		i++;
	}
	return (true);
}

int	ft_numlen(unsigned int number, int radix, bool minus)
{
	int	length;

	length = 0;
	if (minus == true)
		length++;
	while (true)
	{
		length++;
		if (number / radix == 0)
			break ;
		number /= radix;
	}
	return (length);
}
