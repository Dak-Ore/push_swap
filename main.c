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

void	parse_split(char *argv, t_stack *a, t_stack *b)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split(argv, ' ');
	if (!init_stack(str, a))
	{
		ft_putstr_fd("ERROR with argument\n", 2);
		ft_cleaner(a, b);
	}
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack_empty();
	if (!a)
		return (0);
	b = init_stack_empty();
	if (!a)
		return (0);
	if (argc == 2 && ft_strrchr(argv[1], ' '))
		parse_split(argv[1], a, b);
	else
		if (!init_stack(&argv[1], a))
			return (ft_putstr_fd("ERROR with argument\n", 2), ft_cleaner(a, b), 0);
	if (!is_sorted(a, 0))
		smart_sorting(a, b);
	ft_cleaner(a, b);
}
