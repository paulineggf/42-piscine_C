/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:31:43 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 11:34:18 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_check_params(t_bsq *par)
{
	if (par->vide == par->obs || par->vide == par->remp
		|| par->obs == par->remp)
		return (0);
	if (par->vide < 32 || par->vide == 127)
		return (0);
	if (par->obs < 32 || par->obs == 127)
		return (0);
	if (par->remp < 32 || par->remp == 127)
		return (0);
	return (1);
}

int		ft_define_params(char *params, t_bsq *par)
{
	int		i;

	i = 0;
	par->max_x = 0;
	par->size_params = ft_strlen(params);
	while (params[i] >= '0' && params[i] <= '9')
	{
		par->max_x = par->max_x * 10 + params[i++] - '0';
		if (par->max_x >= 2147483648)
			return (0);
	}
	if (i == 0)
		return (0);
	par->vide = params[i++];
	par->obs = params[i++];
	par->remp = params[i++];
	if (!(ft_check_params(par)))
		return (0);
	if (params[i] != '\n')
		return (0);
	return (1);
}
