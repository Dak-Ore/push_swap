/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:52:26 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/9 10:38:18 by rsebasti         ###   ########.fr       */
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
	if (a->pivots)
		free(a->pivots);
	free(a);
	free(b);
}

int	smart_push(int value, t_stack *stack, int i, int sort)
{
	int	*pivot;
	int	nbg;

	nbg = stack->nbg / 2;
	pivot = stack->pivots;
	if (sort == 0)
	{
		if (value >= pivot[nbg + i] && value < pivot[nbg + i + 1])
			return (1);
	}
	else if (sort == 1)
	{
		if (value <= pivot[nbg - i] && value >= pivot[nbg - i - 1])
			return (1);
	}
	else
	{
		if (value >= pivot[i - 1] && value <= pivot[i])
			return (1);
	}
	return (0);
}

int	to_push(t_stack *stack, int i, int sort)
{
	t_list	*lst;
	int		nb;

	lst = stack->first;
	nb = 0;
	while (lst)
	{
		if (smart_push(lst->content, stack, i, sort))
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
	i = a->nbg;
	while (b->size > 0 && i > 0)
	{
		while (to_push(b, i, 2) > 0)
			smart_push_back(a, b, i);
		while (a->last->content < a->first->content)
			ft_rra(a);
		i--;
	}
	while (a->last->content < a->first->content)
		ft_rra(a);
}

int	little_sorting(t_stack *a, t_stack *b)
{
	if (a->size == 2 && b->size == 0)
		return (ft_sa(a), 0);
	if (a->first->content > a->first->next->content &&
        a->first->content > a->first->next->next->content)
    {
        ft_ra(a);
        if (a->first->content > a->first->next->content)
            ft_sa(a);
    }
    else if (a->first->next->content > a->first->content &&
             a->first->next->content > a->first->next->next->content)
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
	if (b->first->content < b->first->next->content &&
	b->first->content < b->first->next->next->content)
    {
        ft_rb(b);
        if (b->first->content < b->first->next->content)
            ft_sb(b);
    }
    else if (b->first->next->content < b->first->content &&
             b->first->next->content < b->first->next->next->content)
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
			ft_pb(a,b);
		else if (!(a->size == 2 && a->first->content == biggest))
			ft_ra(a);
	}
	if (a->first->content == smallest)
		ft_ra(a);
	sort_desc(b);
	while (b->size > 0)
		ft_pa(a,b);
	ft_rra(a);
}

void	smart_sorting(t_stack *a, t_stack *b)
{
	int	*pivots;
	int	i;

	if (a->size >= 6)
	{
		if (a->size >= 500)
			a->nbg = 16;
		else if (a->size >= 200)
			a->nbg = 12;
		else
			a->nbg = 8;
		b->nbg = a->nbg;
		i = -1;
		pivots = malloc(sizeof(int) * a->nbg + 1);
		while (++i < a->nbg)
			pivots[i] = f_elem(a->sorted, (a->size * i / a->nbg));
		pivots[a->nbg] = f_elem(a->sorted, (a->size) - 1);
		a->pivots = pivots; 
		b->pivots = pivots;
		big_sorting(a,b);
	}
	else if (a->size >= 4)
		small_sorting(a,b);
	else
		little_sorting(a,b);
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
	if (!is_sorted(a, 0))
		smart_sorting(a,b);
	ft_cleaner(a, b);
}
