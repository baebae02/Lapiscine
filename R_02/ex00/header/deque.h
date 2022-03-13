/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:41:21 by tson              #+#    #+#             */
/*   Updated: 2022/02/20 21:52:40 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		count;
}t_deque;
void	init_deque(t_deque *p_deque);
void	push_back_deque(t_deque *p_deque,  char *str);
void	push_front_deque(t_deque *p_deque,  char *str);
char	*peek_back_deque(t_deque *p_deque);
char	*peek_front_deque(t_deque *p_deque);
void	pop_back_deque(t_deque *p_deque);
void	pop_front_deque(t_deque *p_deque);
#endif
