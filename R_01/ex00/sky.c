/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:19:14 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/13 17:08:50 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	show(char res[][4]);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
const char	g_arr[24][4] = {"1234", "1243", "1324", "1342", "1423", "1432", \
	"2134", "2143", "2314", "2341", "2413", "2431", \
	"3124", "3142", "3214", "3241", "3412", "3421",
	"4123", "4132", "4213", "4231", "4312", "4321"};

int	cmp(const char *arr, char *str, int j)
{
	int		left;
	int		right;
	char	max[2];
	int		i;

	max[0] = '0';
	max[1] = '0';
	left = 0;
	right = 0;
	i = 0;
	while (i < 4)
	{
		left += (arr[i] > max[0]);
		right += (arr[3 - i] > max[1]);
		if (arr[i] > max[0])
			max[0] = arr[i];
		if (arr[3 - i] > max[1])
			max[1] = arr[3 - i];
		i++;
	}
	if (left == str[16 + 2 * j] - 48 && right == str[24 + 2 * j] - 48)
		return (1);
	else
		return (0);
}

int	cmp_co(char res[4][4], int co, char *str)
{
	int		up;
	int		down;
	int		i;
	char	max[2];

	up = 0;
	down = 0;
	i = 0;
	max[0] = '0';
	max[1] = '0';
	while (i < 4)
	{
		up += (res[i][co] > max[0]);
		down += (res[3 - i][co] > max[1]);
		if (res[i][co] > max[0])
			max[0] = res[i][co];
		if (res[3 - i][co] > max[1])
			max[1] = res[3 - i][co];
		i++;
	}
	if (up == str[co * 2] - 48 && down == str[8 + co * 2] - 48)
		return (1);
	else
		return (0);
}

int	sudoku(char res[4][4])
{
	int	i;
	int	j;
	int	prod;
	int	count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		prod = 1;
		while (j < 4)
			prod *= (res[j++][i] - '0');
		if (prod == 24 && (res[0][i] == '1' || res[1][i] == '1' || \
res[2][i] == '1' || res[3][i] == '1'))
			count++;
		i++;
	}
	if (count == 4)
	{
		show(res);
		return (1);
	}
	else
		return (0);
}

void	arrcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
}

int	recur(char res[][4], int j, char *str)
{
	int	i;
	int	co;

	if (j == 4)
	{
		co = 0;
		while (cmp_co(res, co, str))
			co++;
		if (co == 4 && sudoku(res) == 1)
			return (1);
	}
	i = 0;
	while (i < 24)
	{
		if (cmp(g_arr[i], str, j))
		{
			arrcpy(res[j], g_arr[i]);
			if (recur(res, j + 1, str) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
