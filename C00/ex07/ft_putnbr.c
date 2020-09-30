/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:18:20 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/06 22:18:03 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *tab, int i)
{
	while (i >= 0)
	{
		ft_putchar(tab[i]);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char			tab[11];
	unsigned int	nb2;
	int				i;

	i = 0;
	nb2 = nb;
	if (nb < 0)
		nb2 = nb * -1;
	else if (nb == 0)
		ft_putchar('0');
	while (nb2 > 0)
	{
		tab[i] = nb2 % 10 + 48;
		i++;
		nb2 = nb2 / 10;
	}
	if (nb < 0)
		tab[i] = '-';
	ft_print(tab, i);
}
