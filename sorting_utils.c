/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:28:42 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/18 15:40:17 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_high_low(t_stack *stack, int min, int max, int sort)
{
	t_list	*lst;
	int		best;

	lst = stack->first;
	while (lst && !(lst->content >= min && lst->content < max))
		lst = lst->next;
	best = lst->content;
	lst = lst->next;
	while (lst)
	{
		if (((sort == 0 && lst->content > best)
				|| (sort == 1 && lst->content < best))
			&& (lst->content >= min && lst->content < max))
			best = lst->content;
		lst = lst->next;
	}
	return (best);
}

static void	assign_limits(int **limits, int i, int *pivots)
{
	limits[0][0] = pivots[i];
	limits[0][1] = pivots[i + 1];
}

int	f_nearest(t_stack *stack, int min, int max)
{
	int	highest;
	int	lowest;
	int	reverse_h;
	int	reverse_l;

	highest = f_pos(stack->first, f_high_low(stack, min, max, 0));
	lowest = f_pos(stack->first, f_high_low(stack, min, max, 1)) + 1;
	reverse_h = stack->size - highest;
	reverse_l = stack->size - lowest + 2;
	if ((highest < reverse_h && highest < reverse_l)
		|| (lowest < reverse_h && lowest < reverse_l))
		return (1);
	return (0);
}

void	smart_push_back(t_stack *a, t_stack *b, int i)
{
	int	*limits;
	int	*pivots;

	pivots = a->pivots;
	limits = malloc(sizeof(int) * 2);
	assign_limits(&limits, i - 1, pivots);
	if (b->first->content == f_high_low(b, limits[0], limits[1], 0))
		ft_pa(a, b);
	else if (b->first->content == f_high_low(b, limits[0], limits[1], 1))
	{
		ft_pa(a, b);
		ft_ra(a);
	}
	else if (b->first->content >= limits[0] && b->first->content < limits[1]
		&& f_nearest(b, limits[0], limits[1]))
		ft_rb(b);
	else
		ft_rrb(b);
	free(limits);
}

void	push_back(t_stack *a, t_stack *b)
{
	int	i;

	i = a->nbg;
	while (b->size > 0 && i > 0)
	{
		while (to_push(b, i, 2) > 0)
			smart_push_back(a, b, i);
		while (a->last->content < a->first->content)
			ft_rra(a);
		i--;
	}
}
