/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:24:58 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/08 14:27:49 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (*dest != '\0')
	{
		dest++;
		dest_len++;
	}
	while (*src != '\0' && dest_len + src_len + 1 < size)
	{
		*dest++ = *src++;
		src_len++;
	}
	while (*src++ != '\0')
		src_len++;
	*dest = '\0';
	if (size <= dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
