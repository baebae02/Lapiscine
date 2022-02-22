/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:28:05 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/07 19:00:40 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_word(char *str)
{
	if (*str >= '0' && *str <= '9')
	{
		return (1);
	}
	else if (*str >= 'A' && *str <= 'Z')
	{
		return (2);
	}
	else if (*str >= 'a' && *str <= 'z')
	{
		return (3);
	}
	return (-1);
}

char	*ft_strcapitalize(char *str)
{
	char	*idx;
	int		flag;

	flag = 0;
	idx = str;
	while (*str != '\0')
	{
		if (flag == 0 && check_word(str) == 3)
		{	
			*str -= 32;
			flag = 1;
		}
		else if (check_word (str) < 0)
		{
			flag = 0;
		}
		else if (flag == 1 && check_word (str) == 2)
		{
			*str += 32;
		}	
		else
			flag = 1;
		str++;
	}
	return (idx);
}
