/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:03:08 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/21 11:49:11 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	ft_calcul(char *str, char *base, long int sign);
long int	ft_control_base(char *base);
long int	ft_base_len(char *str);
long int	ft_char_is_in_base(char c, char *base);

char		*putnbr(long int dec, char *base_to, char *str, long int base_len)
{
	long int	i;
	long int	res;
	long int	base_div;

	res = 0;
	base_div = 1;
	i = 0;
	if (dec < 0)
	{
		str[0] = '-';
		i++;
		dec = -dec;
	}
	while ((dec / base_div) >= base_len)
		base_div = base_div * base_len;
	while (base_div > 0)
	{
		res = (dec / base_div) % base_len;
		str[i] = base_to[res];
		i++;
		base_div = base_div / base_len;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_function(char *nbr, char *base_from, char *base_to, char *str)
{
	long int	dec;
	long int	sign;
	long int	i;

	i = 0;
	sign = 1;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	if (ft_char_is_in_base(nbr[i], base_from) >= 0)
	{
		dec = ft_calcul(&nbr[i], base_from, sign);
		putnbr(dec, base_to, str, ft_base_len(base_to));
	}
	else
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;

	if (!(str = malloc(sizeof(char) * 33 + 1)))
		return (NULL);
	if (!ft_control_base(base_from) || !ft_control_base(base_to))
		return (NULL);
	else
		return (ft_function(nbr, base_from, base_to, str));
}
