/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohbae <seohbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:46:19 by tson              #+#    #+#             */
/*   Updated: 2022/02/20 21:52:24 by seohbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/node.h"
#include "./header/deque.h"
#include "./header/mystring.h"
#include "./header/dict.h"
#include <stdlib.h>

void	init_deque(t_deque *p_deque)
{
	p_deque -> head = 0;
	p_deque -> tail = 0;
	p_deque -> count = 0;
}

void	push_back_deque(t_deque *p_deque, char *str)
{
	t_node	*new_node;
	int		len;

	len = str_len(str);
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node -> str = (char *)malloc(sizeof(char) * len);
	str_cpy(new_node -> str, str);
	new_node -> next = 0;
	new_node -> prev = 0;
	if (p_deque -> count == 0)
	{
		p_deque -> head = new_node;
		p_deque -> tail = new_node;
		p_deque -> count++;
		return ;
	}
	new_node -> prev = p_deque -> tail;
	p_deque -> tail -> next = new_node;
	p_deque -> tail = new_node;
	p_deque -> count++;
}

void	push_front_deque(t_deque *p_deque, char *str)
{
	t_node	*new_node;
	int		len;

	len = str_len(str);
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node -> str = (char *)malloc(sizeof(char) * len);
	str_cpy(new_node -> str, str);
	new_node -> next = 0;
	new_node -> prev = 0;
	if (p_deque -> count == 0)
	{
		p_deque -> head = new_node;
		p_deque -> tail = new_node;
		p_deque -> count++;
		return ;
	}
	new_node -> next = p_deque -> head;
	p_deque -> head -> prev = new_node;
	p_deque -> head = new_node;
	p_deque -> count++;
}

char	*peek_back_deque(t_deque *p_deque)
{
	if ((p_deque -> tail) == 0)
		return (0);
	return (p_deque -> tail -> str);
}

char	*peek_front_deque(t_deque *p_deque)
{
	if ((p_deque -> head) == 0)
		return (0);
	return (p_deque -> head -> str);
}

void	pop_back_deque(t_deque *p_deque)
{
	t_node	*p_del;

	if ((p_deque -> count) == 0)
		return ;
	p_del = p_deque -> tail;
	if ((p_deque -> count) == 1)
	{
		free(p_del);
		p_deque -> tail = 0;
		p_deque -> head = 0;
		p_deque -> count = 0;
		return ;
	}
	p_deque -> tail = p_deque -> tail -> prev;
	p_deque -> tail -> next = 0;
	free(p_del -> str);
	free(p_del);
	p_deque -> count--;
}

void	pop_front_deque(t_deque *p_deque)
{
	t_node	*p_del;

	if ((p_deque -> count) == 0)
		return ;
	p_del = p_deque -> head;
	if ((p_deque -> count) == 1)
	{
		free(p_del);
		p_deque -> tail = 0;
		p_deque -> head = 0;
		p_deque -> count = 0;
		return ;
	}
	p_deque -> head = p_deque -> head -> next;
	p_deque -> head -> prev = 0;
	free(p_del);
	p_deque -> count--;
}
