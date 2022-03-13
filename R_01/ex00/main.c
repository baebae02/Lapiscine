/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:23:56 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/13 17:23:57 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	show(char res[][4]);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ex1(char *str);
int		ex2(char *str);
int		check_argv(char *argv);
int		recur(char res[][4], int j, char *str);

int	main(int argc, char **argv)
{
	char	res[4][4];
	int		i;

	i = 0;
	if (argc != 2 && argv[1][31] != '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_argv(argv[1]))
		return (0);
	if (ex1(argv[1]))
		return (0);
	if (ex2(argv[1]))
		return (0);
	if (recur(res, 0, argv[1]) == 0)
		write(1, "Error\n", 6);
	return (0);
}
