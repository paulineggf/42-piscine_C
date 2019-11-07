/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:32:09 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 12:17:21 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

char	*ft_cpy_file(char *argv)
{
	int		fd;
	int		rd;
	char	buf[16385];
	char	*str;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if (!(str = malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	while ((rd = read(fd, buf, 16384)) > 0)
	{
		buf[rd] = '\0';
		if (!(str = ft_strjoin_cat(str, buf)))
			return (NULL);
	}
	if (rd == -1 || close(fd) == -1)
		return (NULL);
	return (str);
}
