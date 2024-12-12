/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:42:58 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/07 13:58:48 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		pos;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (isset(s1[i], set))
		i++;
	while (isset(s1[j], set) && j > i)
		j--;
	str = malloc(sizeof(char) * (j - i + 1) + 1);
	if (!str)
		return (NULL);
	pos = 0;
	while (i <= j)
	{
		str[pos] = s1[i];
		i++;
		pos++;
	}
	str[pos] = '\0';
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
 	char	*trim;

	trim = ft_strtrim("  \t \t \n   \n\n\n\t", " \t\n");
	printf("%s \n", trim);
	free(trim);
}*/