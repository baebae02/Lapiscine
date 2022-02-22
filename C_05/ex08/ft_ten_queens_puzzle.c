/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:04:44 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/15 11:12:10 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

int	pass(int line, int *queen)
{
	int	i;

	i = 0;
	while (i < line)
	{
		if (queen[i] == queen[line] || abs(queen[line] - queen[i]) == line - i)
			return (0);
		i++;
	}
	return (1);
}

void	print_arr(int arr[])
{
	int		i;
	char	ch;

	i = 0;
	ch = '0';
	while (i < 10)
	{
		ch = 48 + arr[i];
		write(1, &ch, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	nQueen(int line, int N, int *queen, int *count)
{
	int	i;

	i = 0;
	if (line == N - 1)
	{
		print_arr(queen);
		*count = *count + 1;
		return ;
	}
	while (i < N)
	{
		queen[line + 1] = i;
		if (pass(line + 1, queen))
			nQueen(line + 1, N, queen, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	N;
	int	queen[10];
	int	count;

	N = 10;
	count = 0;
	nQueen(-1, N, queen, &count);
	return (count);
}
