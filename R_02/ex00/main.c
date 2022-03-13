/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tson <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:33:52 by tson              #+#    #+#             */
/*   Updated: 2022/02/20 12:30:26 by tson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./header/dict.h"
#include "./header/mystring.h"
#include "./header/mynumber.h"
int main(int argc, char* argv[])
{
	t_dict_node	dict[41];

	if (argc == 1)
	{
		//standard entry
		write(1, "Error\n", 6);
	}
	else if (argc == 2)
	{
		// input값 체크
		if (check_input(argv[1]) == -1)
			printf("error\n");
		// number.dict 파일에서 parsing후 문자열로 변환
		init_dict(&dict);
		parsing_dict(&dict, "numbers.dict");
		ft_split(argv[1], dict);
	}
	else if (argc == 3)
	{
		// 새로운 .dict 파일 인자로 받음
		// input값 체크
		// 새로운 .dict 파일에서 parsing후 문자열로 변환
	}
	else
		write(1, "Error\n", 6);
}
