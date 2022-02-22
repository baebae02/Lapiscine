/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:15:01 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/15 09:21:02 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

bool	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\v')
		return (true);
	if (c == '\n' || c == '\r' || c == '\t')
		return (true);
	return (false);
}

bool	ft_base_check(char *str, int len)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = str;
	if (str[0] == '\0' || str[1] == '\0')
		return (false);
	while (*temp)
	{
		if (*temp == '+' || *temp == '-' || is_space(*temp))
			return (false);
		temp++;
	}
	while (i++ < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j++])
				return (false);
		}
	}
	return (true);
}

int	ft_match_base(char *base, char str)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	minus;
	int	result;

	minus = 1;
	result = 0;
	len = ft_len(base);
	if (!ft_base_check(base, len))
		return (0);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (ft_match_base(base, *str) >= 0)
	{
		result *= len;
		result += ft_match_base(base, *str);
		str++;
	}
	return (result * minus);
}
