/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:31:25 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 12:50:15 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

static void	ft_init_params(t_bsq *par, int i)
{
	par->x = 0;
	par->y = i;
	par->size = 1;
}

int			ft_do_frst_line(int fd, char *buf, int *frst_line, t_bsq *par)
{
	int		ret;
	int		i;

	i = 0;
	if ((ret = read(fd, buf, par->max_y)) == -1)
		return (0);
	buf[ret] = '\0';
	while (buf[i] != '\n' && (buf[i] == par->obs || buf[i] == par->vide))
	{
		if (buf[i] == par->obs)
			frst_line[i] = 0;
		if (buf[i] == par->vide)
		{
			if (par->size == 0)
				ft_init_params(par, i);
			frst_line[i] = 1;
		}
		i++;
	}
	if (buf[i] != '\n' || i != par->max_y - 1)
		return (0);
	else
		frst_line[i] = -1;
	return (1);
}

void		ft_fill_sd_line(char *buf, int *sd_line, t_bsq *par, int *i)
{
	while (buf[*i] != '\n' && *i <= par->max_y
	&& (buf[*i] == par->obs || buf[*i] == par->vide))
	{
		if (buf[*i] == par->obs)
			sd_line[*i] = 0;
		if (buf[*i] == par->vide)
			sd_line[*i] = 1;
		*i += 1;
	}
}

int			ft_do_line(char *argv, t_bsq *par)
{
	int		fd;
	int		ret;
	char	*buf;
	int		*frst_line;
	int		*sd_line;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	if (!(buf = malloc(sizeof(char) * ((par->max_y) + 1))))
		return (0);
	if ((ret = read(fd, buf, par->size_params)) == -1)
		return (0);
	if (!(frst_line = malloc(sizeof(int) * par->max_y + 1)))
		return (0);
	if (!(sd_line = malloc(sizeof(int) * par->max_y + 1)))
		return (0);
	if (ft_do_frst_line(fd, buf, frst_line, par) == -1)
		return (0);
	ret = ft_search_square(frst_line, sd_line, par, fd);
	if (ret == 0 || close(fd) == -1)
		return (0);
	return (1);
}
