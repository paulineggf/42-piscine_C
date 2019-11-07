/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:30:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:29:38 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

int		ft_index(char *str, int len, t_dict *tab)
{
	int		i;

	i = 0;
	while (i < 41 && ft_strncmp(str, tab[i].nbr, len))
		i++;
	return (i);
}
