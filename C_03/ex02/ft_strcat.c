/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:31:25 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/08 14:32:22 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*i;

	i = dest;
	while (*i != '\0')
		i++;
	while (*src != '\0')
	{
		*i = *(unsigned char *)src;
		src++;
		i++;
	}
	*i = '\0';
	return (dest);
}
