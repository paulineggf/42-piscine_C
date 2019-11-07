/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:01:41 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/22 20:34:03 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libdict.h"

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char*)malloc((sizeof(char) * ft_strlen(src)) + 1);
	if (dest == 0)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}
