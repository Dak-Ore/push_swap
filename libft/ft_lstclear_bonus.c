/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:53:37 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/11 11:41:52 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*i;

	if (!lst || !*lst)
		return ;
	i = *lst;
	while (i)
	{
		temp = i->next;
		ft_lstdelone(i);
		i = temp;
	}
	*lst = NULL;
}
