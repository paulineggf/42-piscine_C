/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:43:00 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/27 17:21:45 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_do_op(t_do_op *tab, char **argv)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (argv[2][0] == tab[i].str)
		{
			tab[i].ptr(ft_atoi(argv[1]), ft_atoi(argv[3]));
			ft_putchar('\n');
			break ;
		}
		i++;
	}
	if (i == 5)
		ft_putstr("0\n");
}

int		main(int argc, char **argv)
{
	t_do_op	tab[5];

	if (argc == 4)
	{
		tab[0].ptr = &ft_plus;
		tab[0].str = '+';
		tab[1].ptr = &ft_moins;
		tab[1].str = '-';
		tab[2].ptr = &ft_div;
		tab[2].str = '/';
		tab[3].ptr = &ft_mod;
		tab[3].str = '%';
		tab[4].ptr = &ft_mult;
		tab[4].str = '*';
		ft_do_op(tab, argv);
	}
	return (0);
}
