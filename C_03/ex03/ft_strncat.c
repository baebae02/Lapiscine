/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:29:55 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/08 14:31:17 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*i;

	i = dest;
	while (*i != '\0')
		i++;
	while (*src != '\0' && nb > 0)
	{
		*i = *(unsigned char *)src;
		src++;
		i++;
		nb--;
	}
	*i = '\0';
	return (dest);
}
