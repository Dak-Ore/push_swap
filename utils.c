/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:36:05 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/13 15:18:26 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_dup(t_list *lst)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (new);
}

int	is_sorted(t_stack *a)
{
	t_list	*current;
	t_list	*cursor;

	current = a->first;
	while (current)
	{
		cursor = current->next;
		while (cursor)
		{
			if (cursor->content < current->content)
				return (0);
			cursor = cursor->next;
		}
		current = current->next;
	}
	return (1);
}

int	f_pos(t_list *lst, int value)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (value == lst->content)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

int	f_elem(t_list *lst, int pos)
{
	int	i;

	i = 0;
	while (lst && i < pos)
	{
		lst = lst->next;
		i++;
	}
	return (lst->content);
}

t_list	*f_prev(t_stack *a, int value)
{
	t_list	*current;

	current = a->first;
	while (current && current->content != value)
		current = current->next;
	return (current);
}
