/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:24:55 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/06 06:01:49 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curent;

	if (lst)
	{
		if (*lst)
		{
			curent = *lst;
			while (curent->next)
				curent = curent->next;
			curent->next = new;
		}
		else
			*lst = new;
	}
}
