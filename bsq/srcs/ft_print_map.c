/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:11:16 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 15:05:26 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

void	ft_choose_char(char c, t_bsq *res, int *i)
{
	if (((*i / res->max_y) >= (res->x - (res->size - 1)))
		&& ((*i % res->max_y) >= (res->y - (res->size - 1)))
		&& ((*i / res->max_y <= res->x))
		&& ((*i % res->max_y) <= res->y))
		ft_putchar(res->remp);
	else
		ft_putchar(c);
	(*i)++;
}

int		ft_print_map(t_bsq *res, char *argv)
{
	int		i;
	int		ret;
	int		fd;
	char	c;
	char	buffer[4096];

	i = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			break ;
	}
	if (ret == -1)
		return (0);
	while ((ret = read(fd, &c, 1)) > 0)
	{
		ft_choose_char(c, res, &i);
		if (i / res->max_y > res->x)
			break ;
	}
	while ((ret = read(fd, buffer, 4096)) > 0)
		write(1, buffer, ret);
	return (1);
}
