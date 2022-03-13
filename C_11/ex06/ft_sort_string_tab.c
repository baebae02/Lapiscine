/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:44:42 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/22 18:29:00 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	size;
	int	i;

	size = 0;
	while (tab[size])
		size++;
	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap_(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
}
