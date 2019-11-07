/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entre_standard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:20:12 by mcraipea          #+#    #+#             */
/*   Updated: 2019/06/26 15:06:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "bsq.h"
#include <stdlib.h>

static int	ft_create_file(void)
{
	int		ret;
	int		fd;
	char	buffer[16385];

	if (!(fd = open("bsq.cpy", O_WRONLY | O_CREAT | O_TRUNC, 0777)))
		return (0);
	while ((ret = read(0, buffer, 16384)) > 0)
	{
		buffer[ret] = '\0';
		write(fd, buffer, ret);
	}
	if (ret == -1 || close(fd) == -1)
		return (0);
	return (1);
}

void		ft_memset(void *ptr, int c, int len)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char*)ptr;
	i = 0;
	while (i < len)
		str[i++] = c;
}

int			ft_entre_standard(void)
{
	t_bsq	par;
	char	*param;

	ft_create_file();
	ft_memset(&par, 0, sizeof(t_bsq));
	if (!(param = ft_params_line("bsq.cpy", &par)))
		return (0);
	if (!(ft_define_params(param, &par)))
		return (0);
	if (par.max_x == 1)
	{
		if (!(ft_if_single_line("bsq.cpy", &par)))
			return (0);
	}
	else if (par.max_x > 1)
	{
		if (!(ft_do_line("bsq.cpy", &par)))
			return (0);
		if (!(ft_print_map(&par, "bsq.cpy")))
			return (0);
	}
	return (1);
}
