/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:26:48 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/06 22:06:24 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '1';
	c = '2';
	while (!(a == '7' && b == '8' && c == '9'))
	{
		ft_print_result(a, b, c);
		if (c < '9')
			c++;
		else if (c == '9' && b != c - 1)
		{
			b++;
			c = b + 1;
		}
		else if (b == c - 1)
		{
			a++;
			b = a + 1;
			c = b + 1;
		}
	}
	ft_print_result(a, b, c);
}
