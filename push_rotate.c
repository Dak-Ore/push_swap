/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:43:52 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/13 16:07:33 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	t_list	*temp;

	if (!a || !b || a->size == 0)
		return ;
	temp = a->first;
	a->first = a->first->next;
	if (b->size == 0)
	{
		temp->next = NULL;
		b->last = temp;
	}
	else
		temp->next = b->first;
	b->first = temp;
	b->size = b->size + 1;
	a->size = a->size - 1;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_list	*temp;

	if (!a || !b || b->size == 0)
		return ;
	temp = b->first;
	b->first = b->first->next;
	if (a->size == 0)
	{
		temp->next = NULL;
		a->last = temp;
	}
	else
		temp->next = a->first;
	a->first = temp;
	a->size = a->size + 1;
	b->size = b->size - 1;
	ft_putstr_fd("pb\n", 1);
}

void	ft_ra(t_stack *a)
{
	t_list	*temp;

	if (!a || a->size <= 1)
		return ;
	temp = a->first;
	a->first = temp->next;
	a->last->next = temp;
	temp->next = NULL;
	a->last = temp;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack *b)
{
	t_list	*temp;

	if (!b || b->size <= 1)
		return ;
	temp = b->first;
	b->first = temp->next;
	b->last->next = temp;
	temp->next = NULL;
	b->last = temp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	t_list	*temp;

	if (!a || a->size <= 1)
	{
		temp = a->first;
		a->first = temp->next;
		a->last->next = temp;
		temp->next = NULL;
		a->last = temp;
	}
	if (!b || b->size <= 1)
	{
		temp = b->first;
		b->first = temp->next;
		b->last->next = temp;
		temp->next = NULL;
		b->last = temp;
	}
	ft_putstr_fd("rr\n", 1);
}
