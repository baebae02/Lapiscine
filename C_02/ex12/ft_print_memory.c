/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseoki <junseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:29:18 by junseoki          #+#    #+#             */
/*   Updated: 2022/02/19 11:10:46 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	print_hex_n(long long num, int n)
{
	char	*hex;
	if (n == 0)
		return ;
	hex = "0123456789abcdef";
	print_hex_n(num / (16 * 16), n - 1);
	write (1, hex + ((unsigned char)num / 16 % 16), 1);
	write (1, hex + ((unsigned char)num % 16), 1);
}

void	print_str(char *str, int n)
{
	int	i;
	i = 0;
	write(1, " ", 1);
	while (i < n && i < 16)
	{
		if (' ' <= *(str + i) && *(str + i) <= '~')
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_space(int i)
{
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	if (size == 0)
		return (addr);
	print_hex_n((long long)addr, 8);
	i = 0;
	write(1, ":", 1);
	while (i < (int)size && i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		print_hex_n(*((char *)addr + i), 1);
		i++;
	}
	print_space(i);
	print_str(addr, size);
	if ((int)(size - 16) <= 0)
		size = 0;
	else
		size -= 16;
	ft_print_memory((char *)addr + 16, size);
	return (addr);
}

int main()
{
	char str[] = {"0123456789012345ABCDEFGHIJK"};
	ft_print_memory(str,50);
}
