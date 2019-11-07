/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:15:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:34:02 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void	ft_hundreds(char *str, t_dict *tab, int *i, int *k)
{
	if (str[*i] != '0')
	{
		ft_putstr(tab[str[*i] - 48].let);
		ft_putstr(" ");
		ft_putstr(tab[28].let);
		if (!((*i == ft_strlen(str) - 3)
		&& str[*i + 1] == '0' && str[*i + 2] == '0'))
			ft_putstr(" ");
	}
	*k += 2;
	*i += 1;
}

void	ft_tens(char *str, t_dict *tab, int *i, int *k)
{
	if (str[*i] == '1')
	{
		ft_putstr(tab[10 + str[*i + 1] - 48].let);
		if (*i != ft_strlen(str) - 2)
			ft_putstr(" ");
	}
	else if (str[*i] >= '2' && str[*i] <= '9')
	{
		ft_putstr(tab[18 + str[*i] - 48].let);
		if (!((*i == ft_strlen(str) - 2) && str[*i + 1] == '0'))
			ft_putstr(" ");
	}
	*k -= 1;
	*i += 1;
}

void	ft_units(char *str, t_dict *tab, int *i, int *j)
{
	if (str[*i - 1] != '1' && str[*i] != '0')
	{
		ft_putstr(tab[str[*i] - 48].let);
		if (*i != ft_strlen(str) - 1)
			ft_putstr(" ");
	}
	if (*j > 28)
	{
		if ((str[*i] >= '1' && str[*i] <= '9')
		|| (str[*i - 1] >= '1' && str[*i - 1] <= '9')
		|| (str[*i - 2] >= '1' && str[*i - 2] <= '9'))
			ft_putstr(tab[*j].let);
		if (!((str[*i + 3] == '0' && str[*i + 1] == '0' && str[*i + 2] == '0')))
			ft_putstr(" ");
		*j -= 1;
	}
	*i += 1;
}

void	ft_print_number(char *str, t_dict *tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (ft_strlen(str) > 3)
		j = ft_strlen(str) / 3;
	if (!(k = ft_strlen(str) % 3))
		j -= 1;
	j = j + 28;
	if (ft_strlen(str) == 1 && str[i] == '0')
		ft_putstr(tab[0].let);
	while (i < ft_strlen(str))
	{
		if (k == 0)
			ft_hundreds(str, tab, &i, &k);
		if (k == 2)
			ft_tens(str, tab, &i, &k);
		if (k == 1)
		{
			ft_units(str, tab, &i, &j);
			k = 0;
		}
	}
}
