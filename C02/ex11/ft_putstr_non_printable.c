/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:11:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/10 21:11:32 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_char_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

void	ft_convert_int_hex(unsigned int nb, char *tab)
{
	int				i;
	unsigned int	nb2;
	int				stock[20];

	i = 0;
	nb2 = nb;
	while (nb > 0)
	{
		stock[i] = nb % 16;
		nb = nb / 16;
		i++;
	}
	if (nb2 < 16)
		ft_putchar('0');
	while (i > 0)
	{
		i--;
		ft_putchar(tab[stock[i]]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_char_is_printable(str[i])))
		{
			ft_putchar('\\');
			ft_convert_int_hex(*(unsigned char*)(str + i), "0123456789abcdef");
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
