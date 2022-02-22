/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:52:22 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/21 13:42:15 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen_(char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
		i++;
	return (i);
}

int	ft_total_len(char **strs, int size, int sep_len)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size - 1)
	{
		len += ft_strlen_(strs[i]);
		len += sep_len;
		i++;
	}
	len += ft_strlen_(strs[i]);
	return (len);
}

char	*ft_make_total(char **strs, int size, char *sep)
{
	char	*result;
	int		total_len;

	total_len = 0;
	if (!size)
	{
		result = malloc(sizeof(char));
		*result = 0;
		return (result);
	}
	total_len = ft_total_len(strs, size, ft_strlen_(sep));
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*total;
	int		offset;
	int		word_index;
	int		char_index;

	total = ft_make_total(strs, size, sep);
	if (!total)
		return (0);
	offset = 0;
	word_index = 0;
	while (word_index < size)
	{
		char_index = 0;
		while (strs[word_index][char_index] != '\0')
			total[offset++] = strs[word_index][char_index++];
		char_index = 0;
		while (sep[char_index] != '\0' && word_index < (size - 1))
			total[offset++] = sep[char_index++];
		word_index++;
	}	
	total[offset++] = '\0';
	return (total);
}
