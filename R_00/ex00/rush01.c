/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmle <jeongmle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:07:11 by jeongmun          #+#    #+#             */
/*   Updated: 2022/02/05 09:25:55 by jeongmle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	is_corner(int x, int y, int i, int j)
{
	if (i == 0 && j == 0)
		return (1);
	else if (i == 0 && j == y - 1)
		return (2);
	else if (i == x - 1 && j == 0)
		return (2);
	else if (i == x - 1 && j == y - 1)
		return (1);
	else
		return (0);
}

int	is_edge(int x, int y, int i, int j)
{
	if (i == 0 || i == x - 1)
		return (1);
	else if (j == 0 || j == y - 1)
		return (2);
	else
		return (0);
}

void	put_enter(int x, int y)
{
	if (x > 0 && y > 0)
		ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (is_corner(x, y, i, j) == 1)
				ft_putchar('/');
			else if (is_corner(x, y, i, j) == 2)
				ft_putchar('\\');
			else if (is_edge(x, y, i, j) != 0)
				ft_putchar('*');
			else
				ft_putchar(' ');
			i ++;
		}
		put_enter(x, y);
		j ++;
	}
}
