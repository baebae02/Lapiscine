/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:11:35 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/15 10:12:06 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	i = 0;
	fact = 1;
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		fact *= ++i;
	}
	return (fact);
}
