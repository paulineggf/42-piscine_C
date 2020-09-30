/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:20:45 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/08 16:50:49 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_last_line(int x)
{
	int		i;

	i = 2;
	ft_putchar(92);
	if (x > 1)
	{
		while (i < x)
		{
			ft_putchar('*');
			i++;
		}
		ft_putchar('/');
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
		ft_putchar('*');
		if (x > 1)
		{
			j = x - 2;
			while (j > 0)
			{
				ft_putchar(' ');
				j--;
			}
			ft_putchar('*');
		}
		ft_putchar('\n');
		i--;
	}
}

void	print_first_line(int x)
{
	int		i;

	i = 2;
	ft_putchar('/');
	if (x > 1)
	{
		while (i < x)
		{
			ft_putchar('*');
			i++;
		}
		ft_putchar(92);
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
