/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 03:48:40 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/05 04:32:13 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ns;

	i = 0;
	ns = (unsigned char *) s;
	while (i < n)
	{
		if (ns[i] == (unsigned char) c)
			return ((void *)&ns[i]);
		i++;
	}
	return (NULL);
}
