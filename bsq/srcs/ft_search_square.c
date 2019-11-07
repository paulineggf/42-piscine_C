/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:09:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 14:08:15 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

static void		ft_swap(int **s1, int **s2)
{
	int		*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int				ft_search_square(int *frst_line, int *sd_line, t_bsq *par
	, int fd)
{
	char	*buf;
	int		ret;
	int		i;
	int		compteur_line;

	compteur_line = 0;
	if (!(buf = malloc(sizeof(char) * ((par->max_y) + 1))))
		return (0);
	while ((ret = read(fd, buf, par->max_y)) > 0)
	{
		buf[ret] = '\0';
		compteur_line++;
		i = 0;
		ft_fill_sd_line(buf, sd_line, par, &i);
		if (buf[i] != '\n' || i != par->max_y - 1)
			return (0);
		else
			sd_line[i] = -1;
		ft_algo(frst_line, sd_line, par, compteur_line);
		ft_swap(&frst_line, &sd_line);
	}
	if (compteur_line != par->max_x - 1 || compteur_line == 0)
		return (0);
	return (1);
}
