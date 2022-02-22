/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:31:34 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/21 14:12:39 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	is_space(char c);
bool	ft_base_check(char *str);
int		ft_numlen(unsigned int number, int radix, bool minus);
int		ft_strlen(char *str);

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

int	ft_match(char *base, char *nbr, int len)
{
	int	result;
	int	match_idx;

	result = 0;
	match_idx = 0;
	while (ft_match_base(base, *nbr) != -1)
	{
		match_idx = ft_match_base(base, *nbr);
		result *= len;
		result += match_idx;
		nbr++;
	}
	return (result);
}

char	*ft_convert_base2(unsigned int nbr, char *base, bool minus)
{
	int		index;
	int		base_len;
	int		nbr_len;
	char	*string;

	index = 0;
	base_len = ft_strlen(base);
	nbr_len = ft_numlen(nbr, base_len, minus);
	string = (char *)malloc((nbr_len + 1) * sizeof(char));
	if (!string)
		return (0);
	if (minus)
	{
		string[0] = '-';
		index++;
	}
	while (index < nbr_len)
	{
		string[nbr_len - (!minus) - index] = base[nbr % base_len];
		index++;
		nbr /= base_len;
	}
	string[nbr_len] = '\0';
	return (string);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				len;
	bool			minus;
	int				match_idx;
	unsigned int	result;

	if (!ft_base_check(base_from) || !ft_base_check(base_to))
		return (NULL);
	len = ft_strlen(base_from);
	match_idx = 0;
	minus = false;
	result = 0;
	while (is_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*(nbr++) == '-')
			minus = !minus;
	}
	result = ft_match(base_from, nbr, len);
	if (result == 0)
		minus = false;
	return (ft_convert_base2(result, base_to, minus));
}
