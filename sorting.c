/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:18:06 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/18 15:44:22 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sorting(t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (++i < a->nbg / 2)
	{
		while (to_push(a, i, 0) > 0 || to_push(a, i, 1) > 0)
		{
			if (smart_push(a->first->content, a, i, 0))
				ft_pb(a, b);
			else if (smart_push(a->first->content, a, i, 1))
			{
				ft_pb(a, b);
				ft_rb(b);
			}
			else
				ft_ra(a);
		}
	}
	push_back(a, b);
}

int	little_sorting(t_stack *a, t_stack *b)
{
	if (a->size == 2 && b->size == 0)
		return (ft_sa(a), 0);
	if (a->first->content > a->first->next->content
		&& a->first->content > a->first->next->next->content)
	{
		ft_ra(a);
		if (a->first->content > a->first->next->content)
			ft_sa(a);
	}
	else if (a->first->next->content > a->first->content
		&& a->first->next->content > a->first->next->next->content)
	{
		ft_rra(a);
		if (a->first->content > a->first->next->content)
			ft_sa(a);
	}
	else
		if (a->first->content > a->first->next->content)
			ft_sa(a);
	return (1);
}

void	sort_desc(t_stack *b)
{
	if (b->first->content < b->first->next->content
		&& b->first->content < b->last->content)
	{
		ft_rb(b);
		if (b->first->content < b->first->next->content)
			ft_sb(b);
	}
	else if (b->first->next->content < b->first->content
		&& b->first->next->content < b->last->content)
	{
		ft_rrb(b);
		if (b->first->content < b->first->next->content)
			ft_sb(b);
	}
	else
		if (b->first->content < b->first->next->content)
			ft_sb(b);
}

void	small_sorting(t_stack *a, t_stack *b)
{
	int	smallest;
	int	biggest;

	smallest = f_elem(a->sorted, 0);
	biggest = f_elem(a->sorted, a->size - 1);
	while (a->size != 2)
	{
		if (a->first->content != smallest && a->first->content != biggest)
			ft_pb(a, b);
		else if (!(a->size == 2 && a->first->content == biggest))
			ft_ra(a);
	}
	if (a->first->content == smallest)
		ft_ra(a);
	sort_desc(b);
	while (b->size > 0)
		ft_pa(a, b);
	ft_rra(a);
}

void	smart_sorting(t_stack *a, t_stack *b)
{
	int	*pivots;
	int	i;

	if (a->size >= 6)
	{
		if (a->size >= 200)
			a->nbg = 16;
		else if (a->size >= 100)
			a->nbg = 8;
		else
			a->nbg = 4;
		b->nbg = a->nbg;
		i = -1;
		pivots = malloc(sizeof(int) * (a->nbg + 1));
		while (++i < a->nbg)
			pivots[i] = f_elem(a->sorted, (a->size * i / a->nbg));
		pivots[a->nbg] = f_elem(a->sorted, (a->size) - 1);
		a->pivots = pivots;
		b->pivots = pivots;
		big_sorting(a, b);
	}
	else if (a->size >= 4)
		small_sorting(a, b);
	else
		little_sorting(a, b);
}
