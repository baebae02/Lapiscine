/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tson <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:54:12 by tson              #+#    #+#             */
/*   Updated: 2022/02/20 17:55:12 by tson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# include <stdlib.h>
typedef struct s_dict_node
{
	char	key[100];
	char	value[100];
	int		check;
}t_dict_node;

void	init_dict(t_dict_node (*dict)[41]);
char	*get_value(t_dict_node dict[41], int idx);
int		get_idx(t_dict_node dict[41], char *key);
int		parsing_dict(t_dict_node (*dict)[41], char *dict_name);
#endif
