/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:23:16 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/11 10:47:02 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_addr_hex(unsigned long long nb, char *tab)
{
	int		stock[15];
	int		i;

	i = 0;
	while (i < 15)
	{
		stock[i] = nb % 16;
		nb = nb / 16;
		i++;
	}
	while (i > 0)
		write(1, &tab[stock[--i]], 1);
}

void	ft_convert_int_hex(unsigned long long nb, char *tab)
{
	int						stock[15];
	int						i;
	unsigned long long		nb2;

	i = 0;
	nb2 = nb;
	while (nb > 0)
	{
		stock[i] = nb % 16;
		nb = nb / 16;
		i++;
	}
	if (nb2 < 16 && nb2 > 0)
		write(1, "0", 1);
	if (nb2 == 0)
		write(1, "00", 2);
	while (i > 0)
		write(1, &(tab[stock[--i]]), 1);
}

void	ft_print_txt(void *addr, int *i, int *j, int *compt)
{
	int	x;

	x = 0;
	if (*(char*)(addr + *i) == '\0')
	{
		while (*compt <= 40)
		{
			write(1, " ", 1);
			*compt = *compt + 1;
		}
		*i = *i - (*j * 2);
	}
	else
		*i = *i - 16;
	while (x < 16 && *(char*)(addr + *i))
	{
		if (*(unsigned char*)(addr + *i) < 32
				|| *(unsigned char *)(addr + *i) > 126)
			write(1, ".", 1);
		else
			write(1, (unsigned char*)(addr + *i), 1);
		*i = *i + 1;
		x = x + 1;
	}
}

void	ft_print_hex_char(void *addr, int *i, int *j, int *compt)
{
	while (*j < 8 && *(char*)(addr + *i))
	{
		ft_convert_int_hex(*(unsigned char*)(addr + *i), "0123456789abcdef");
		*i = *i + 1;
		ft_convert_int_hex(*(unsigned char*)(addr + *i), "0123456789abcdef");
		if (*(char*)(addr + *i) != '\0')
			write(1, " ", 1);
		*i = *i + 1;
		*j = *j + 1;
		*compt = *compt + 5;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		k;
	int					i;
	int					j;
	int					compt;

	k = 0;
	i = 0;
	while (k < size && *(char*)(addr + i))
	{
		ft_convert_addr_hex((unsigned long long)(addr + i), "0123456789abcdef");
		write(1, ": ", 2);
		j = 0;
		compt = 0;
		ft_print_hex_char(addr, &i, &j, &compt);
		ft_print_txt(addr, &i, &j, &compt);
		if (*(char*)(addr + i) == '\0')
			write(1, ".", 1);
		write(1, "\n", 1);
		k++;
	}
	return (addr);
}
