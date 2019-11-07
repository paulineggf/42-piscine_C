/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:20:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/25 22:51:05 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_algo(int *l1, int *l2, t_bsq *res, int x)
{
	int		i;

	i = 0;
	if (l2[0] == 1 && res->size == 0)
	{
		res->x = x;
		res->y = i;
		res->size = 1;
	}
	i++;
	while (l2[i] != -1)
	{
		if (l2[i] != 0)
			l2[i] = ft_plus(l2[i - 1], l1[i], l1[i - 1]);
		if (l2[i] > res->size)
		{
			res->x = x;
			res->y = i;
			res->size = l2[i];
		}
		i++;
	}
}
