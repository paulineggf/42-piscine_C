/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:52:39 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 15:06:34 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

int		ft_while_file(char *argv)
{
	t_bsq	par;
	char	*param;

	par.size = 0;
	if (!(param = ft_params_line(argv, &par)))
		return (0);
	if (!(ft_define_params(param, &par)))
		return (0);
	if (par.max_x == 1)
	{
		if (!(ft_if_single_line(argv, &par)))
			return (0);
	}
	else if (par.max_x > 1)
	{
		if (!(ft_do_line(argv, &par)))
			return (0);
		if (!(ft_print_map(&par, argv)))
			return (0);
	}
	return (1);
}
