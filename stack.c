/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:43:16 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/12 12:39:21 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	res;
	long	isneg;

	res = 0;
	isneg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			isneg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (res * isneg);
}

int	is_valid_number(char *nb, t_stack *stack)
{
	int		i;
	long	nbv;
	t_list	*curr;

	i = 0;
	while (nb[i] && ft_isdigit(nb[i]))
		i++;
	nbv = ft_atol(nb);
	if (nbv > INT_MAX || nbv < INT_MIN)
		return (0);
	curr = stack->first;
	while (curr)
	{
		if (curr->content == (int) nbv)
			return (0);
		curr = curr->next;
	}
	return (i == (int) ft_strlen(nb));
}

t_stack	*init_stack_empty(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->size = 0;
	return (stack);
}

int	init_stack(char **str, t_stack *stack)
{
	int		i;
	t_list	*lst;

	i = 1;
	if (is_valid_number(str[0], stack) == 0)
		return (0);
	lst = ft_lstnew(ft_atoi(str[0]));
	stack->first = lst;
	while (str[i])
	{
		if (is_valid_number(str[i], stack) == 0)
			return (stack->size = i, 0);
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	stack->last = ft_lstlast(lst);
	stack->size = i - 1;
	return (1);
}
