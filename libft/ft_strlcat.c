/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:08:41 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/08 11:02:46 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	size_dest;
	size_t	size_src;

	i = 0;
	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dest >= dsize)
		return (dsize + size_src);
	while (src[i] && size_dest + i < dsize - 1)
	{
		dst[size_dest + i] = src[i];
		i++;
	}
	dst[size_dest + i] = '\0';
	return (size_dest + size_src);
}
