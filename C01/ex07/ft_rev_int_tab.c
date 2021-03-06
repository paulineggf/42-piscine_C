/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:59:25 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/08 13:03:31 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		x;

	i = 0;
	while (i < size)
	{
		x = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = x;
		i++;
		size--;
	}
}
