/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:43:54 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/11 16:40:16 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdellast(t_list *lst)
{
	if (!lst || !lst->next)
		return ;
	while (lst->next->next)
		lst = lst->next;
	lst->next = NULL;
}

void	ft_reverse_rotate(t_stack *s)
{
	t_list	*temp;

	temp = s->last;
	ft_lstdellast(s->first);
	s->last = ft_lstlast(s->first);
	s->last->next = NULL;
	temp->next = s->first;
	s->first = temp;
}

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
