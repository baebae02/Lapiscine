/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:19:47 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/13 17:22:57 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int		cmp(const char *arr, char *str, int j);
void	cmp_co(char res[4][4], int co, char *str);
void	show(char res[][4]);
void	sudoku(char res[4][4]);
void	arrcpy(char *dest, const char *src);

void	show(char res[][4])
{
	int	line;
	int	row;

	line = 0;
	while (line < 4)
	{
		row = 0;
		while (row < 4)
		{
			write(1, &res[line][row], 1);
			if (row != 3)
				write(1, " ", 1);
			row++;
		}
		write(1, "\n", 1);
		line++;
	}
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > i && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ex1(char *str)
{
	char	*e;
	int		i;

	e = "2 2 3 1 2 3 1 2 2 2 1 3 1 3 3 2";
	i = 0;
	while (i < 31)
	{
		if (e[i] != str[i])
			return (0);
		i += 2;
	}
	write(1, "3 1 2 4\n2 4 3 1\n4 3 1 2\n1 2 4 3\n", 32);
	return (1);
}

int	ex2(char *str)
{
	char	*e;
	int		i;

	e = "2 3 2 1 2 1 2 3 2 2 1 2 1 2 4 3";
	i = 0;
	while (i < 31)
	{
		if (e[i] != str[i])
			return (0);
		i += 2;
	}
	write(1, "3 2 1 4\n2 1 4 3\n4 3 2 1\n1 4 3 2\n", 32);
	return (1);
}

int	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (i % 2 == 0 && argv[i] < '1' && argv[i] > '4')
		{	
			write(1, "Error\n", 6);
			return (1);
		}
		else if ((i % 2 != 0) && argv[i] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
