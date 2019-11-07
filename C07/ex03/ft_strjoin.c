/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:43:29 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/21 16:23:29 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_while_cat(int size, char *str, char **strs, char *sep)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
		if (i + 1 != size)
			i++;
		else
			break ;
	}
	ft_strcat(str, strs[i]);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		res;
	char	*str;

	i = -1;
	res = 0;
	if (!(str = malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = 0;
	if (size <= 0)
		return (str);
	while (++i < size)
		res = res + ft_strlen(strs[i]);
	if (!(str = (char*)malloc(sizeof(char) * res +
		ft_strlen(sep) * (size - 1) + 1)))
		return (0);
	str[0] = 0;
	return (ft_while_cat(size, str, strs, sep));
}
