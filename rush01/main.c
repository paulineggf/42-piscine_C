/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:36:05 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/16 20:47:31 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str);
int		**ft_init_tab(int **tab, char *str);
void	ft_print_tab(int **tab);
int		ft_control_param(char *str);
int		ft_backtracking(int **tab, int x, int y, int n);

int		main(int argc, char **argv)
{
	int		**tab;
	int		i;

	i = 0;
	tab = (int**)malloc(sizeof(int*) * 6);
	while (i < 6)
	{
		tab[i] = (int*)malloc(sizeof(int) * 6);
		i++;
	}		
	if (argc == 2)
	{
		if (ft_control_param(argv[1]))
		{
			tab = ft_init_tab(tab, argv[1]);
			if (!ft_backtracking(tab, 1, 1, 1))
				ft_putstr("Error\n");
		}
		else
			ft_putstr("Error\n");
	}
	return (0);
}
