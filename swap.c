/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:43:58 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/11 16:39:57 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	int	temp;

	if (a->size < 2 || !a)
		return ;
	temp = a->first->content;
	a->first->content = a->first->next->content;
	a->first->next->content = temp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *b)
{
	int	temp;

	if (b->size < 2 || !b)
		return ;
	temp = b->first->content;
	b->first->content = b->first->next->content;
	b->first->next->content = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size >= 2 && a)
	{
		temp = a->first->content;
		a->first->content = a->first->next->content;
		a->first->next->content = temp;
	}
	if (b->size >= 2 && b)
	{
		temp = b->first->content;
		b->first->content = b->first->next->content;
		b->first->next->content = temp;
	}
	ft_putstr_fd("ss\n", 1);
}
