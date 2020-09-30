/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:16:38 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/16 20:50:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_control_row(int left, int right, int **tab, int x)
{
	int		cmp_left;
	int		cmp_right;
	int		y;

	cmp_left = 1;
	cmp_right = 1;
	y = 1;
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
	if (left == cmp_left && right == cmp_right)
		return (1);
	return (0);
}
