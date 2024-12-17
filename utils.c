/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:36:05 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/17 14:51:51 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_dup(t_list *lst)
{
	t_list	*new;

	new = ft_lstnew(lst->content);
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (new);
}

int	is_sorted(t_stack *a, int order)
{
	t_list	*current;
	t_list	*cursor;

	current = a->first;
	while (current)
	{
		cursor = current->next;
		while (cursor)
		{
			if (cursor->content < current->content && order == 0)
				return (0);
			if (cursor->content > current->content && order == 1)
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
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current && i < pos)
	{
		current = current->next;
		i++;
	}
	return (current->content);
}

t_list	*f_prev(t_stack *a, int value)
{
	t_list	*current;

	current = a->first;
	while (current && current->content != value)
		current = current->next;
	return (current);
}
