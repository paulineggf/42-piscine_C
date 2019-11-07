/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:39:53 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/20 11:05:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int				*tab;
	int				cmp;
	int				i;
	long			range;

	i = -1;
	range = max - min;
	if (min >= max)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(int) * range)))
		return (NULL);
	cmp = max - min - 1;
	while (i++ < cmp)
	{
		tab[i] = min;
		min++;
	}
	return (tab);
}
