/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:52:26 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/16 15:33:29 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putnbr(int nb)
{
	ft_putnbr_fd(nb, 1);
	write(1, "\n", 1);
}

void	ft_cleaner(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		ft_lstclear(&a->first);
	if (b->size > 0)
		ft_lstclear(&b->first);
	if (a->sorted)
		ft_lstclear(&a->sorted);
	free(a);
	free(b);
}

int	smart_push(int value, int *pivot, int i, int sort)
{
	if (sort == 0)
	{
		if (value >= pivot[8 + i] && value < pivot[8 + i + 1])
			return (1);
	}
	else if (sort == 1)
	{
		if (value <= pivot[8 - i] && value >= pivot[8 - i - 1])
			return (1);
	}
	else
	{
		if (value >= pivot[i - 1] && value <= pivot[i])
			return (1);
	}
	return (0);
}

int	to_push(t_stack *stack, int *pivot, int i, int sort)
{
	t_list	*lst;
	int		nb;

	lst = stack->first;
	nb = 0;
	while (lst)
	{
		if (smart_push(lst->content, pivot, i, sort))
			nb++;
		lst = lst->next;
	}
	return (nb);
}

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

void	assign_limits(int **limits, int i, int *pivots)
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
	reverse_l = stack->size - lowest + 1;
	if ((highest < reverse_h && highest < reverse_l)
		|| (lowest < reverse_h && lowest < reverse_l))
		return (1);
	return (0);
}

void	smart_push_back(t_stack *a, t_stack *b, int *pivots, int i)
{
	int	*limits;

	limits = malloc(sizeof(int) * 2);
	assign_limits(&limits, i - 1, pivots); 
	if (b->first->content == f_high_low(b, limits[0], limits[1], 0))
		ft_pa(a,b);
	else if (b->first->content == f_high_low(b, limits[0], limits[1], 1))
	{
		ft_pa(a,b);
		ft_ra(a);
	}
	else if (b->first->content >= limits[0] && b->first->content < limits[1]
			&& f_nearest(b, limits[0], limits[1]))
		ft_rb(b);
	else
		ft_rrb(b);
	free(limits);
}

void	try_sorting(t_stack *a, t_stack *b)
{
	int	tiers[17];
	int	i;

	i = -1;
	while (++i < 16)
		tiers[i] = f_elem(a->sorted, (a->size * i / 16));
	tiers[16] = f_elem(a->sorted, (a->size) - 1);
	i = -1;
	while (++i < 8)
	{
		while (to_push(a, tiers, i, 0) > 0 || to_push(a, tiers, i, 1) > 0)
		{
			if (smart_push(a->first->content, tiers, i, 0))
				ft_pb(a, b);
			else if (smart_push(a->first->content, tiers, i, 1))
			{
				ft_pb(a, b);
				ft_rb(b);
			}
			else
				ft_ra(a);
		}
	}
	ft_lstiter(a->first, &putnbr);
	i = 16;
	while (b->size > 0 && i > 0)
	{
		while (to_push(b, tiers, i, 2) > 0)
			smart_push_back(a, b, tiers, i);
		while (a->last->content < a->first->content)
			ft_rra(a);
		i--;
	}
	while (a->last->content < a->first->content)
		ft_rra(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	if (argc < 2)
		return (0);
	a = init_stack_empty();
	if (!a)
		return (0);
	b = init_stack_empty();
	if (!a)
		return (0);
	if (argc == 2 && ft_strrchr(argv[1], ' '))
		str = ft_split(argv[1], ' ');
	else
		str = &argv[1];
	if (!init_stack(str, a))
		return (ft_putstr_fd("ERROR with argument\n", 2), ft_cleaner(a, b), 0);
	try_sorting(a,b);
	// ft_putstr_fd("a", 1);
	// ft_lstiter(a->first, &putnbr);
	ft_cleaner(a, b);
}
