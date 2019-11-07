/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:08:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 16:47:44 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

int		ft_control_param(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > 39)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
