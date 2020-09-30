/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:15:47 by aaliev            #+#    #+#             */
/*   Updated: 2019/06/16 20:48:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_control_row(int left, int right, int **tab, int x);
int		ft_control_col(int up, int down, int **tab, int y);
int		check_nbr(int **tab, int x, int y, int n);
void	ft_print_tab(int **tab);


int		ft_backtracking(int **tab, int x, int y, int n)
{
	if (n <= 4)
	{
		if (check_nbr(tab, x, y, n) && x != 4 && y != 4)
		{
			tab[x][y] = n;
			ft_backtracking(tab, x, y + 1, 1);
		}
		else if (check_nbr(tab, x, y, n) && x != 4 && y == 4)
		{
			tab[x][y] = n;
			if (ft_control_row(tab[x][0], tab[x][5], tab, x))
				ft_backtracking(tab, x + 1, 1, 1);
			else
			{
				tab[x][y] = 0;
				ft_backtracking(tab, x, y, n + 1);
			}
		}
		else if (check_nbr(tab, x, y, n) && x == 4 && y != 4)
		{
			tab[x][y] = n;
			if (ft_control_col(tab[0][y], tab[5][y], tab, y))
				ft_backtracking(tab, x, y + 1, 1);
			else
			{
				tab[x][y] = 0;
				ft_backtracking(tab, x, y, n + 1);
			}
		}
		else if (check_nbr(tab, x, y, n) && x == 4 && y == 4)
		{
			tab[x][y] = n;
			if (ft_control_col(tab[x][0], tab[x][5], tab, x) && 
				ft_control_row(tab[0][y], tab[5][y], tab, y))
			{
				ft_print_tab(tab);
				return (1);
			}
			else
				ft_backtracking(tab, x, y, n + 1);
		}
		else
				ft_backtracking(tab, x, y, n + 1);
	}
	else
		tab[x][y] = 0;
	return (0);
}
