/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:11:24 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/25 14:11:25 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_plus(int lft, int up, int lftup)
{
	int		res;

	res = 0;
	if (lft <= up && lft <= lftup)
		res = lft + 1;
	else if (up <= lftup && up <= lft)
		res = up + 1;
	else if (lftup <= lft && lftup <= up)
		res = lftup + 1;
	return (res);
}
