/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:19:52 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:44:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libdict.h"

char	*ft_cpy_file(void)
{
	int		fd;
	int		rd;
	char	buf[16385];
	char	*str;

	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
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
	{
		ft_putstr("Error return -1\n");
		return (NULL);
	}
	return (str);
}
