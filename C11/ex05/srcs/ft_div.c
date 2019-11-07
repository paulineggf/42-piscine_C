/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:43:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/27 15:05:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_div(int nb1, int nb2)
{
	if (nb2 == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(nb1 / nb2);
}