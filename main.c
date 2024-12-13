/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:52:26 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/13 16:29:07 by rsebasti         ###   ########.fr       */
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

int	to_push(t_stack *stack, int pivot)
{
	t_list	*lst;
	int		i;

	lst = stack->first;
	i = 0;
	while (lst)
	{
		if (lst->content <= pivot)
			i++;
		lst = lst->next;
	}
	return (i);
}

void	try_sorting(t_stack *a, t_stack *b)
{
	int		mediane;

	mediane = f_elem(a->sorted, a->size / 2);
	while (to_push(a, mediane) > 0)
	{
		if (a->first->content <= mediane)
		{
			if (a->first->content > a->first->next->content)
				ft_sa(a);
			ft_pb(a,b);
		}
		else
		{
			if (a->first->content > a->first->next->content)
				ft_sa(a);
			else if (a->first->content < a->last->content)
				ft_rra(a);
			else
				ft_ra(a);
		}
	}
	while (!is_sorted(a))
	{
		if (a->first->content > a->first->next->content)
			ft_sa(a);
		else if (a->first->content < a->last->content)
			ft_rra(a);
		else
			ft_ra(a);
	}
	while (!is_sorted(b))
	{
		if (b->first->content > b->first->next->content)
			ft_sb(b);
		else if (b->first->content < b->last->content)
			ft_rrb(b);
		else
			ft_rb(b);
	}
	while (b->size > 0)
	{
		ft_rrb(b);
		ft_pa(a, b);
	}
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
