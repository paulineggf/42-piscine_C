/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:49:44 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/13 12:18:18 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(unsigned int nb, char *base, unsigned int div)
{
	if (nb < div)
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr(nb / div, base, div);
		ft_putnbr(nb % div, base, div);
	}
}

int		ft_control_base(int size, char *base)
{
	int		i;
	int		j;

	i = 0;
	if (size <= 1)
		return (0);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
				return (0);
			j++;
		}
		i++;
	}
	if (base[i] == '+' || base[i] == '-'
		|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
		return (0);
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (ft_control_base(i, base))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = (unsigned int)nb * -1;
			ft_putnbr(nb, base, i);
		}
		else
			ft_putnbr((unsigned int)nb, base, i);
	}
}
