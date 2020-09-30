/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:28:19 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/16 21:15:02 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_tab(int **tab);
int		ft_check_nb(int x, int y, int **tab, int nb);

int		ft_complete_tab(int **tab)
{
	int		x;
	int		y;

	x = 1;
	while (x <= 4)
	{
		y = 1;
		while (y <= 4)
		{
			if (tab[x][y] == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_control_tab(int **tab)
{
	int		x;
	int 	y;
	int		cmp_left;
	int		cmp_right;
	int		cmp_up;
	int		cmp_down;

	if (ft_complete_tab(tab))
	{
		x = 1;
		while (x <= 4)
		{
			y = 1;
			cmp_left = 1;
			cmp_right = 1;
			while (y < 4 && tab[x][y] != 4)
			{
				if (tab[x][y + 1] > tab[x][1])
					cmp_left += 1;
				y++;
			}
			y = 4;
			while (y > 1 && tab[x][y] != 4)
			{
				if (tab[x][y - 1] > tab[x][4])
					cmp_right += 1;
				y--;
			}
			if (cmp_left != tab[x][0] || cmp_right != tab[x][5])
				return (0);
			x++;
		}
		y = 1;
		while (y <= 4)
		{
			x = 1;
			cmp_up = 1;
			cmp_down = 1;
			while (x < 4 && tab[x][y] != 4)
			{
				if (tab[x + 1][y] > tab[1][y])
					cmp_up += 1;
				x--;
			}
			x = 4;
			while (x > 1 && tab[x][y] != 4)
			{
				if (tab[x - 1][y] > tab[4][y])
					cmp_down += 1;
				x--;
			}
			if (cmp_up != tab[0][y] || cmp_down != tab[5][y])
				return (0);
			y++;
		}
		return (1);
	}
	else
		return (0);
}

void	ft_fill_nb(int **tab)
{
	int		nb;
	int		x;
	int		y;
	int		nb_tmp;

	printf("debut fonction\n");
	x = 1;
	while (x <= 4)
	{
		y = 1;
		while (y <= 4)
		{
			if (tab[x][y] != 0)
			{
				y++;
				continue ;
			}
			nb = 1;
			while (nb <= 4)
			{
				if (!ft_check_nb(x, y, tab, nb))
				{
					nb++;
					continue ;
				}
				nb_tmp = tab[x][y];
				tab[x][y] = nb;
				ft_fill_nb(tab);
				//printf("TEST2@\n");
				if (ft_control_tab(tab))
				{
					//printf("TEST@\n");
					ft_print_tab(tab);
					return ;
				}
				tab[x][y] = nb_tmp;
				nb++;
			}
			return ;
			y++;
		}
		x++;
	}
	return ;
}
