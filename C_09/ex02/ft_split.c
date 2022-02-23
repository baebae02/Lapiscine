/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:14:39 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/22 17:23:04 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	ft_check(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (true);
		charset++;
	}
	return (false);
}

int	count_words(char *str, char *charset)
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (str[idx])
	{
		while (str[idx] != '\0' && ft_check(str[idx], charset))
			idx++;
		if (str[idx] && !ft_check(str[idx], charset))
		{
			cnt++;
			while (str[idx] && !ft_check(str[idx], charset))
				idx++;
		}
	}
	return (cnt);
}

char	*ft_malloc(char *str, char *charset)
{
	int		idx;
	int		cnt;
	char	*string;

	cnt = 0;
	idx = 0;
	while (str[cnt] && !ft_check(str[cnt], charset))
		cnt++;
	string = (char *)malloc(sizeof(char) * (cnt + 1));
	while (str[idx] && !ft_check(str[idx], charset))
	{
		string[idx] = str[idx];
		idx++;
	}
	string[idx] = '\0';
	return (string);
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	char	**arr;

	idx = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (*str)
	{
		while (*str && ft_check(*str, charset))
			str++;
		if (*str && !ft_check(*str, charset))
		{
			arr[idx] = ft_malloc(str, charset);
			idx++;
			while (*str && !ft_check(*str, charset))
				str++;
		}
	}
	arr[idx] = 0;
	return (arr);
}
#include <stdio.h>
int main(void)
{
	printf("----ex05----\n");
		char **str_arr;
		int i;
		str_arr = ft_split("Hello World Cat\tDog\nPizza School"," \n");
		for(i=0;str_arr[i] != 0; i++)
			printf("%s\n",str_arr[i]);
		for(i=0;str_arr[i] != 0; i++)
			free(str_arr[i]);
		free(str_arr);	
		str_arr = ft_split("Hello World Cat\tDog\nPizza School"," World");
		for(i=0;str_arr[i] != 0; i++)
			printf("%s\n",str_arr[i]);
		for(i=0;str_arr[i] != 0; i++)
			free(str_arr[i]);
		free(str_arr);
}