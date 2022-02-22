/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:11:49 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/15 12:12:42 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*temp;

	temp = argv[0];
	if (argc > 0)
	{
		while (*temp != '\0')
		{
			write(1, temp, 1);
			temp++;
		}
		write(1, "\n", 1);
	}
}
