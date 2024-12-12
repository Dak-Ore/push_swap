/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:40:59 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/03 13:11:11 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char) c)
		s++;
	if (*s == (unsigned char) c)
		return ((char *)s);
	return (0);
}
