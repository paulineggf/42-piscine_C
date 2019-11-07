/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:53:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/13 14:59:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_in_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_control_base(int size, char *base, char c)
{
	int		i;
	int		j;

	i = 0;
	if (size <= 1)
		return (0);
	while (c != base[i] && base[i])
		i++;
	if (base[i] == '\0')
		return (0);
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[i] <= ' ' || (base[i] >= 9 && base[i] <= 13))
				return (0);
		}
	}
	if (base[i] == '+' || base[i] == '-'
		|| base[i] <= ' ' || (base[i] >= 9 && base[i] <= 13))
		return (0);
	return (1);
}

int		ft_calcul(char *str, char *base, int div, int sign)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (ft_char_is_in_base(str[i], base) >= 0)
	{
		res = res * div + ft_char_is_in_base(str[i], base);
		i++;
	}
	return (res * sign);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		div;

	i = 0;
	div = 0;
	sign = 1;
	i = 0;
	while (base[div] != '\0')
		div++;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (ft_control_base(div, base, str[i]))
		return (ft_calcul(&str[i], base, div, sign));
	else
		return (0);
}
