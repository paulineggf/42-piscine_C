/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:40:14 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/16 12:34:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_control_param(char *str)
{

	int		i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (i < 31)
	{
		if (str[i] < '1' || str[i] > '4')
			return (0);
		i += 2;
	}
	i = 1;
	while (i < 31)
	{
		if (str[i] != ' ')
			return (0);
		i += 2;
	}
	return (1);
}
