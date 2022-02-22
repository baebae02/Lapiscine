/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:42:49 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/21 13:41:41 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range_(int min, int max)
{
	int	len;
	int	i;
	int	*arr;

	i = 0;
	len = max - min;
	if (len <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * (len + 1));
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range_(min, max);
	if (*range == NULL)
		return (0);
	return (max - min);
}
