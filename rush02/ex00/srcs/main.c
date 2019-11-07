/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:00:16 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:44:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libdict.h"

int		main(int argc, char **argv)
{
	char	*str;
	t_dict	*tab;

	if (!(tab = malloc(sizeof(t_dict) * 41)))
		return (0);
	if (!(str = ft_cpy_file()))
		return (0);
	tab = cpynbr(tab);
	if (!(tab = ft_putstruct(str, tab)))
		return (0);
	if (argc == 2)
	{
		if (!(ft_control_param(argv[1])))
			ft_putstr("Error\n");
		else
		{
			ft_print_number(argv[1], tab);
			ft_putstr("\n");
		}
	}
	else
		ft_putstr("Error\n");
	return (0);
}
