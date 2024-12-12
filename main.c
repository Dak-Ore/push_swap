/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:52:26 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/12 12:20:50 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putnbr(int nb)
{
	ft_putnbr_fd(nb, 1);
	write(1, "\n", 1);
}

void	ft_cleaner(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		ft_lstclear(&a->first);
	if (b->size > 0)
		ft_lstclear(&b->first);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	if (argc < 2)
		return (0);
	a = init_stack_empty();
	if (!a)
		return (0);
	b = init_stack_empty();
	if (!a)
		return (0);
	if (argc == 2 && ft_strrchr(argv[1], ' '))
		str = ft_split(argv[1], ' ');
	else
		str = &argv[1];
	if (!init_stack(str, a))
		return (ft_putstr_fd("ERROR with argument\n", 2), ft_cleaner(a, b), 0);
	ft_putstr_fd("pile a:\n", 1);
	ft_lstiter(a->first, &putnbr);
	ft_cleaner(a, b);
}
