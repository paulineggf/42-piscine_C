/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:08:39 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/06 22:14:15 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char a, char b, char c, char d)
{
	if (c * 10 + d > a * 10 + b)
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(' ');
		ft_putchar(c);
		ft_putchar(d);
		if ((a * 10 + b) + (c * 10 + d) != 1253)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_add_number(char *a, char *b, char *c, char *d)
{
	if (*d < '9')
		*d = *d + 1;
	else if (*d == '9' && *c < '9')
	{
		*c = *c + 1;
		*d = '0';
	}
	else if (*d == '9' && *c == '9' && *b < '9')
	{
		*b = *b + 1;
		*c = '0';
		*d = '0';
	}
	else if (*d == '9' && *c == '9' && *b == '9' && *a < '9')
	{
		*d = '0';
		*c = '0';
		*b = '0';
		*a = *a + 1;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	while (!(a == '9' && b == '8' && c == '9' && d == '9'))
	{
		ft_print(a, b, c, d);
		ft_add_number(&a, &b, &c, &d);
	}
	ft_print(a, b, c, d);
}
