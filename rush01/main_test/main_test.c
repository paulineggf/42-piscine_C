/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:10:47 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/16 16:39:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		**ft_init_tab(int **tab, char *str);
int		ft_control_row(int left, int right, int **tab, int x);

int		main(void)
{
	int		**tab;
	int		i;
	int		res;

	i = 0;
	tab = (int**)malloc(sizeof(int*) * 6);
	while (i < 6)
	{
		tab[i] = (int*)malloc(sizeof(int) * 6);
		i++;
	}
	tab = ft_init_tab(tab, "1 2 3 4 1 2 3 4 2 2 3 3 3 2 3 4");
	tab[1][1] = 3;
	tab[1][2] = 1;
	tab[1][3] = 2;
	tab[1][4] = 4;
	res = ft_control_row(2, 3, tab, 1);
	printf("res : %d\n", res);
	return (0);
}
