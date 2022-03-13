/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mynumber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:48:33 by tson              #+#    #+#             */
/*   Updated: 2022/02/20 21:52:56 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./header/mynumber.h"
#include "./header/node.h"
#include "./header/dict.h"
#include "./header/deque.h"
#include "./header/mystring.h"
#include <stdio.h>
char *unit[13] = {"", "thousand", "million", "billion", "trillion", "quatrillion", "quintillion"};
// void	init_unit(char *unit, t_dict_node dict[41])
// {
// 	int	i;
// 	char *arr[14];

// 	i = 1;
// 	while (i <= 12)
// 	{
// 		*arr[i] = dict[28 + i].value;
// 		printf("ellele:%s\n", dict[28+i].value);
// 		i++;
// 	}
// 	unit = arr;
// }

void	num_to_str(t_deque *p_deque, t_dict_node dict[41], int num,  char *str)
{
	int		div;
	int		idx;
	int		tmp;
	char	dst[10];

	if (num >= 100)
	{
		div = num / 100;
		itoa(div, dst);
		tmp = get_idx(dict, dst);
		push_back_deque(p_deque, get_value(dict, tmp));
		tmp = get_idx(dict, "100");
		push_back_deque(p_deque, get_value(dict, tmp));
	}
	num %= 100;
	idx = 27;
	while (num != 0 && idx >= 0)
	{
		if ((num / ft_atoi(dict[idx].key)) >= 1)
		{
			push_back_deque(p_deque, dict[idx].value);
			num %= ft_atoi(dict[idx].key);
		}
		idx--;
	}
	push_back_deque(p_deque, str);
}

void ft_split(char *str, t_dict_node dict[41])
{
	int			count;
	int			len;
	// char		*unit[13]; // 0's index is null
	int			i;
	int			j;
	int			result;
	t_deque		deque;
	int			temp_len;

	count = 0;
	i = 0;
	result = 0;
	len = str_len(str);
	// init_unit(&unit, dict);
	printf("HERERE");
	if(len % 3 != 0)
	{
		while (i < len % 3)
		{
			result *= 10;
			result += str[i] - 48;
			i++;
		}
		num_to_str(&deque, dict, result, unit[(len - i) / 3]);
		printf("1:%d\n", result);
		printf("%s\n", unit[(len - i) / 3]);
	}
	while (str[i] != '\0')
	{
		j = 0;
		result = 0;
		while (j < 3)
		{
			result *= 10;
			result += str[i] - 48;
			j++;
			i++;
		}
		num_to_str(&deque, dict, result, unit[(len - i) / 3]);
		printf("2:%d\n", result);
		printf("%s\n", unit[(len - i) / 3]);
	}
}
