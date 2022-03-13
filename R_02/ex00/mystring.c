/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:22:38 by tson              #+#    #+#             */
/*   Updated: 2022/02/20 21:52:53 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/mystring.h"

void    str_cat(char *dest, char *src)
{
    char    *i;
    i = dest;
    while (*i != '\0')
        i++;
    while (*src != '\0')
    {
        *i = *(unsigned char *)src;
        src++;
        i++;
    }
    *i = '\0';
}

void	itoa(int src,char* dst)
{
   int temp = 100000000;
   int index = 0;

   // src가 0이면 아래의 연산을 수행할 수 없으므로
   if (src == 0) { 
      dst[0] = '0';
      dst[1] = '\0'; 
      return; 
   }
   // 앞의 0 생김방지
   while(src % temp == src) {
      temp /= 10;
   }
   while(temp >= 1) { 
      dst[index] = src / temp + '0';
      index++;
      src -= (src/temp)*temp;
      temp /= 10;
   }
   dst[index] = '\0'; 
}

int	str_len( char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

void	str_cpy(char *dest,  char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
		*dest++ = *src++;
}

unsigned int	ft_atoi(char *str)
{
	long long	ret_val;
	int			idx;

	ret_val = 0;
	idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			return (-1);
		idx = 1;
	}
	while (str[idx] >= 48 && str[idx] <= 57)
	{
		ret_val *= 10;
		ret_val += str[idx] - 48;
		if (ret_val > 4294967295)
			return (-1);
		idx++;
	}
	return (ret_val);
}

int	check_input(char *str)
{
	int			idx;
	int			count;

	idx = 0;
	count = 0;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			return (-1);
		idx = 1;
	}
	while (str[idx] != '\0')
	{
		if (!(str[idx] >= 48 && str[idx] <= 57))
			return (-1);
		count++;
		idx++;
		if (count >= 40)
			return (-1);
	}
	return (0);
}
