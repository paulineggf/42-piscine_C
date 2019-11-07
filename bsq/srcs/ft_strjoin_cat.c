/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_cat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:09:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 01:58:40 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

char	*ft_strjoin_cat(char *str, char *buf)
{
	char	*new;

	if (!(new = malloc((sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1)))))
		return (NULL);
	new = ft_strcpy(new, str);
	new = ft_strcat(new, buf);
	free(str);
	return (new);
}
