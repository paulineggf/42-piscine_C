/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:19:11 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:34:17 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libdict.h"

t_dict	*ft_putstruct(char *str, t_dict *tab)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str[j])
	{
		i = j;
		k = 0;
		while (str[j] && str[j] >= '0' && str[j] <= '9')
			j++;
		k = j;
		while (str[j] && (ft_isspace(str[k]) || str[k] == ':'))
			k++;
		if (!(tab[ft_index(str + i, j - i, tab)].let = ft_strdup_rl(str + k)))
			return (NULL);
		while (str[j] && str[j] != '\n')
			j++;
		j++;
	}
	return (tab);
}
