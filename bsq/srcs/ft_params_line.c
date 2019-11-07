/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:30:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 11:26:59 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "bsq.h"

int			ft_max_y(t_bsq *par, int fd, char *buf, int ret)
{
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		par->max_y += 1;
		if (buf[0] == '\n')
			break ;
	}
	if (par->max_y <= 1)
		return (0);
	if (ret == -1 || close(fd) == -1)
		return (0);
	return (1);
}

char		*ft_params_line(char *argv, t_bsq *par)
{
	int		fd;
	char	buf[2];
	int		ret;
	char	*params;

	par->max_y = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if (!(params = malloc(sizeof(char) * 1)))
		return (NULL);
	params[0] = '\0';
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		if (!(params = ft_strjoin_cat(params, buf)))
			return (NULL);
		if (buf[0] == '\n')
			break ;
	}
	if (ret == -1 || !(ft_max_y(par, fd, buf, ret)))
		return (NULL);
	return (params);
}
