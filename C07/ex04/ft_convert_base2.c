/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:53:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/21 11:47:25 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int		ft_base_len(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int		ft_char_is_in_base(char c, char *base)
{
	int			i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long int		ft_control_base(char *base)
{
	int			i;
	int			j;
	int			base_len;

	i = 0;
	base_len = ft_base_len(base);
	if (base_len < 2)
		return (0);
	i = -1;
	while (++i < base_len - 1)
	{
		j = i;
		while (++j < base_len)
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

long int		ft_calcul(char *str, char *base, long int sign)
{
	int			i;
	long int	res;
	long int	div;

	i = 0;
	res = 0;
	div = ft_base_len(base);
	while (ft_char_is_in_base(str[i], base) >= 0)
	{
		res = res * div + ft_char_is_in_base(str[i], base);
		i++;
	}
	return (res * sign);
}
