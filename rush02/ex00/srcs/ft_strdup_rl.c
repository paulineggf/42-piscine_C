/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_rl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:34:40 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:14:55 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libdict.h"

char	*ft_strdup_rl(char *src)
{
	int		len_src;
	char	*dest;

	len_src = 0;
	while (src[len_src] != '\n')
		len_src++;
	if (!(dest = malloc(sizeof(char) * len_src + 1)))
		return (NULL);
	dest = ft_strncpy(dest, src, len_src);
	return (dest);
}
