/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:01:01 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/19 11:19:45 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *str)
{
	char	*copied;
	int		i;
	int		len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	copied = (char *)malloc(sizeof(char) * (len + 1));
	if (!copied)
		return (NULL);
	while (str[i] != '\0')
	{
		copied[i] = str[i];
		i++;
	}
	copied[i] = '\0';
	return (copied);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*total;

	i = 0;
	total = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!total)
		return (NULL);
	while (i < ac)
	{
		total[i].size = ft_strlen(av[i]);
		total[i].str = av[i];
		total[i].copy = ft_strcpy(av[i]);
		i++;
	}
	total[i].str = 0;
	return (total);
}
