/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:51:56 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/03 04:56:54 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (us1[i] == us2[i] && us1[i] && i < n - 1)
		i++;
	return (us1[i] - us2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d", ft_strncmp("abcd", "abce", 3));
	printf("%d", strncmp("abcd", "abce", 3));
	return (1);
}
*/