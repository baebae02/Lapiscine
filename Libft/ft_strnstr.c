/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:10:35 by seohbae           #+#    #+#             */
/*   Updated: 2022/03/13 16:14:22 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, cosnt char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if(*needle == NULL)
		return ((char *)haystack);
	if(!len)
		return (NULL);
	if(*haystack == NULL)
		return (NULL);
	while ((haystack[i] != NULL) && (i <= (len - ft_strlen(needle))))
	{
		if (ft_strstr(haystack, needle, i) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
