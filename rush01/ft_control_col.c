/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:16:55 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/16 20:50:30 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_control_col(int up, int down, int **tab, int y)
{
	int		cmp_up;
	int		cmp_down;
	int		x;

	cmp_up = 1;
	cmp_down = 1;
	x = 1;
	while (x < 4 && tab[x][y] != 4)
	{
		if (tab[x + 1][y] > tab[1][y])
			cmp_up += 1;
		x++;
	}
	x = 4;
	while (x > 1 && tab[x][y] != 4)
	{
		if (tab[x][y - 1] > tab[4][y])
			cmp_down += 1;
		x--;
	}
	if (up == cmp_up && down == cmp_down)
		return (1);
	return (0);
}
