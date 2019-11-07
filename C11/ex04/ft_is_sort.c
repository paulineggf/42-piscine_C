/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:04:06 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/27 21:38:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (res == 0 && i + 1 < length)
	{
		res = f(tab[i], tab[i + 1]);
		i++;
	}
	while (i < length - 1)
	{
		if (!(f(tab[i], tab[i + 1]) == res || f(tab[i], tab[i + 1]) == 0))
			return (0);
		i++;
	}
	return (1);
}
