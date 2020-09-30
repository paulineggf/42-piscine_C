/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:24:41 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/16 15:12:07 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**ft_fill_x(char *str, int *i, int **tab, int x)
{
	int		y;

	y = 1;
	while (y <= 4)
	{
		tab[x][y] = str[(*i)] - 48;
		*i = *i + 2;
		y++;
	}
	return (tab);
}

int		**ft_fill_y(char *str, int *i, int **tab, int y)
{
	int		x;

	x = 1;
	while (x <= 4)
	{
		tab[x][y] = str[(*i)] - 48;
		*i = *i + 2;
		x++;
	}
	return (tab);
}

int		**ft_init_tab(int **tab, char *str)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (x <= 5)
	{
		y = 0;
		while (y <= 5)
		{
			tab[x][y] = 0;
			y++;
		}
		x++;
	}
	tab = ft_fill_x(str, &i, tab, 0);
	tab = ft_fill_x(str, &i, tab, 5);
	tab = ft_fill_y(str, &i, tab, 0);
	tab = ft_fill_y(str, &i, tab, 5);
	return (tab);
}
