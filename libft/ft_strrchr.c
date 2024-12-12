/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:49:59 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/03 13:12:07 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*start)
		start++;
	while (s != start)
	{
		if (*start == (unsigned char) c)
			return ((char *)start);
		start--;
	}
	if (*start == (unsigned char) c)
		return ((char *)start);
	return (0);
}
