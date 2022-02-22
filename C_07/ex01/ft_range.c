/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:32:51 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/21 13:39:32 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	i;
	int	*arr;

	i = 0;
	len = max - min;
	if (len <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (len + 1));
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
