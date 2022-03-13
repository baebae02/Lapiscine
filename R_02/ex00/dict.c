/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:56:41 by tson              #+#    #+#             */
/*   Updated: 2022/02/22 13:35:44 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/node.h"
#include "./header/deque.h"
#include "./header/dict.h"
#include "./header/mystring.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
void	push_back_deque(t_deque *p_deque, char *str);
int check_kv_push(char *str, t_dict_node (*dict)[41])
{
	char *key;
	char value[100];
	char key_atoi[10];
	int	i;
	int idx;
	int j;

	i = 0;
	idx = 0;
	key = 0;
	key_atoi[0] = '\0';
	value[0] = '\0';
	while(str[i] >= '0' && str[i] <= '9')
	{
		key_atoi[i] = str[i];
		i++;
	}
	key_atoi[i] = '\0';
	while (str[i] == ' ')
		i++;
	if (str[i] == ':')
		i++;
	else
		return (-1);
	while (str[i] == ' ')
		i++;
	j = 0;
	while (str[i] > 31 && str[i] < 127)
	{
		if(str[i] == ' ')
		{
			value[j] = str[i];
			while(str[i] == ' ')
			{
				i++;
			}
		}
		if (!(str[i] > 31 && str[i] < 127))
			return (-1);
		value[j] = str[i];
		i++;
		j++;
	}
	value[j] = '\0';
	idx = get_idx(*dict, key_atoi); //todo : first word
	if ((*dict)[idx].check == 1)
		return (-1);
	str_cpy((*dict)[idx].value, value);
	return (1);
}

void	init_extra_dict(t_dict_node (*dict)[41], int i, int idx)
{
	char	dst[100];
	char	temp[10];

	dst[0] = '1';
	dst[1] = '0';
	dst[2] = '0';
	dst[3] = '0';
	dst[4] = '\0';
	i *= 10;
	itoa(i, temp);
	str_cpy((*dict)[idx].key, temp);
	(*dict)[idx].check = 0;
	idx++;
	while (idx < 41)
	{
		str_cat(dst, "000");
		str_cpy((*dict)[idx].key, dst);
		(*dict)[idx].check = 0;
		idx++;
	}
}

void	init_dict(t_dict_node (*dict)[41])
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (i <= 20)
	{
		itoa(i, (*dict)[idx].key);
		(*dict)[idx].check = 0; // 채워넣지 않았다.
		i++;
		idx++;
	}
	i--;
	while (i < 100)
	{
		i += 10;
		itoa(i, (*dict)[idx].key);
		(*dict)[idx].check = 0;
		idx++;
	}
	init_extra_dict(dict, i, idx);
}

char	*get_value(t_dict_node dict[41], int idx)
{
	return (dict[idx].value);
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s1 == *s2)
    {
		if (*s1 != *s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
        s1++;
        s2++;
    }
    return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

int get_idx(t_dict_node dict[41], char *key) 
{
    int idx;

    idx = 0;
    while (idx < 41)
    {
        if (ft_strcmp(key, dict[idx].key) == 0)
            return (idx);
        idx++;
    }
    return (-1); // no
}

int	parsing_dict(t_dict_node (*dict)[41], char *dict_name)
{
	int		fd;
	char	buf;
	char	str[100];
	int		idx;

	fd = open(dict_name, O_RDONLY);
	idx = 0;
	if (fd == -1)
		return (0); // dict name error
	while (read(fd, &buf, 1) > 0)
	{
		idx = 0;
		while (buf != '\n')
		{
			str[idx] = buf;
			idx++;
			read(fd, &buf, 1);
		}
		str[idx] = '\0';
		if (check_kv_push(str, dict) == -1) //check_key_value 
		{
			return (0);
		}
		else if (check_kv_push(str, dict) == 1)
			continue;
	}
	return (1);
}
