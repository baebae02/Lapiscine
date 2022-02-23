/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:28:51 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/21 18:37:31 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	x_ft_put_number(int number)
{
	if (number > 9)
		x_ft_put_number(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}
void	r_ft_put_number(int number)
{
	if (number > 9)
		x_ft_put_number(number / 10);
	write(1, &"9876543210"[number % 10], 1);
}

void    plus_ft_put_number(int number)
{
    write(1, &"0123456789"[number+1], 1);
}

void    ft_foreach(int *tab, int length, void(*f)(int))
{
    if (length <= 0)
        return ;
    (*f)(tab[0]);
    ft_foreach(tab + 1, length - 1, f);
}

#include <stdio.h>
int		main(void)
{
	int	index;
	int	*tab;
	int	length;

	length = 10;
	tab = malloc(length * sizeof(int));
	index = 0;
	while (index < length)
	{
		tab[index] = index;
		index++;
	}
	ft_foreach(tab, length, &x_ft_put_number);
    printf("\n");
	ft_foreach(tab, length, &r_ft_put_number);
    printf("\n");
	ft_foreach(tab, length, &plus_ft_put_number);
}