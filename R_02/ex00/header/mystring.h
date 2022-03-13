/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:34:54 by tson              #+#    #+#             */
/*   Updated: 2022/02/20 21:52:46 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTRING_H
# define MYSTRING_H
void			str_cat(char *dest, char *src);
void			itoa(int src, char *dst);
int				str_len( char *str);
void			str_cpy(char *dest,  char *src);
unsigned int	ft_atoi(char *str);
int	check_input(char *str);
#endif
