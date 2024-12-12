/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:12:35 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/07 10:39:27 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(long n)
{
	size_t	nb;

	nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = getsize(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[i] = '0';
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char	*itoa = ft_itoa(-65456164);
	printf("%s \n", itoa);
	free(itoa);
}*/
