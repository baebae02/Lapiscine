/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:35:35 by seohbae           #+#    #+#             */
/*   Updated: 2022/02/23 13:37:58 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdbool.h>

int		ft_atoi(char *str);
bool	ft_is_space(char c);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

int		ft_add(int a, int b);
int		ft_minus(int a, int b);
int		ft_div(int a, int b);
int		ft_multi(int a, int b);
int		ft_modul(int a, int b);

#endif
