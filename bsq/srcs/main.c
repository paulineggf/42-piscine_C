/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 10:51:02 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 17:23:41 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		if (!(ft_entre_standard()))
			write(2, "map error\n", 10);
	}
	while (i < argc)
	{
		if (!(ft_while_file(argv[i])))
			write(2, "map error\n", 10);
		i++;
		if (i < argc)
			ft_putchar('\n');
	}
	return (0);
}
