/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:37:10 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/15 12:10:11 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;

	i = 0;
	if (nb > 0)
	{
		while (i * i <= (unsigned int) nb)
		{
			if (i * i == (unsigned int) nb)
				return (i);
			i++;
		}
	}
	return (0);
}