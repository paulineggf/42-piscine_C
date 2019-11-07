/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_single_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:20:12 by mcraipea          #+#    #+#             */
/*   Updated: 2019/06/26 11:42:05 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "bsq.h"

void		ft_print_single_line(char *buf, t_bsq *par)
{
	int		i;

	i = 0;
	while (buf[i] != par->vide && buf[i] != '\n' && buf[i] != '\0')
		ft_putchar(buf[i++]);
	if (buf[i] == par->vide && buf[i] != '\0' && buf[i] != '\n')
	{
		ft_putchar(par->remp);
		i++;
	}
	while (buf[i] != '\0')
		ft_putchar(buf[i++]);
}

int			ft_check_buf(char *buf, t_bsq *par, int ret)
{
	int		i;

	i = 0;
	if (buf[ret - 1] != '\n')
		return (0);
	while (i < par->max_y - 1)
	{
		if (buf[i] != par->vide && buf[i] != par->obs)
			return (0);
		i++;
	}
	return (1);
}

int			ft_if_single_line(char *argv, t_bsq *par)
{
	int		fd;
	int		ret;
	char	*buf;
	char	c;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	if (!(buf = malloc(sizeof(char) * (par->max_y + 1))))
		return (0);
	while ((ret = read(fd, buf, 1) > 0))
	{
		buf[ret] = '\0';
		if (buf[0] == '\n')
			break ;
	}
	if ((ret = read(fd, buf, par->max_y)) == -1)
		return (0);
	if (read(fd, &c, 1) || close(fd) == -1)
		return (0);
	buf[ret] = '\0';
	if (!ft_check_buf(buf, par, ret))
		return (0);
	ft_print_single_line(buf, par);
	return (1);
}
