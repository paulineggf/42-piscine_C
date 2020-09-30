/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:17:55 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/08 16:49:41 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_last_line(int x)
{
	int		i;

	i = 2;
	ft_putchar('o');
	if (x > 1)
	{
		while (i < x)
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	print_inter_line(int x, int y)
{
	int		i;
	int		j;

	i = y - 2;
	while (i > 0)
	{
		ft_putchar('|');
		if (x > 1)
		{
			j = x - 2;
			while (j > 0)
			{
				ft_putchar(' ');
				j--;
			}
			ft_putchar('|');
		}
		ft_putchar('\n');
		i--;
	}
}

void	print_first_line(int x)
{
	int		i;

	i = 2;
	ft_putchar('o');
	if (x > 1)
	{
		while (i < x)
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (y > 0 && x > 0)
	{
		print_first_line(x);
		print_inter_line(x, y);
		if (y > 1)
			print_last_line(x);
	}
}
