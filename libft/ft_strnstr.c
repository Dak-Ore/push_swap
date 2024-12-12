/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:03:36 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/05 04:33:07 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && big[i + j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
