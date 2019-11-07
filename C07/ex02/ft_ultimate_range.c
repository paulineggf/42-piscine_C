/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:17:35 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/20 14:39:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_range(int ***range, int min, int max)
{
	int				cmp;
	int				i;

	i = -1;
	cmp = max - min - 1;
	while (i++ < cmp)
	{
		(**range)[i] = min;
		min++;
	}
}

int		ft_ultimate_range(int **range, int min, int max)
{
	long			mm;

	mm = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	if (!(*range = (int*)malloc(sizeof(int) * mm)))
		return (-1);
	ft_range(&range, min, max);
	if (mm > 2147483647)
		return (-1);
	return (max - min);
}
