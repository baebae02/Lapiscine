/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:36:41 by seohbae           #+#    #+#             */
/*   Updated: 2022/03/13 15:40:52 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)

{
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (*dst)
	{
		dst++;
		dest_len++;
	}
	while (*src && dest_len + src_len + 1 < dstsize)
	{
		*dst++ = *src++;
		src_len++;
	}
	while (*src++)
		src_len++;
	*dest = '\0';
	if (dstsize <= dest_len)
		return (src_len + dstsize);
	else
		return (src_len + dest_len);
}
