/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpynbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:32:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:44:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

t_dict	*cpynbr2(t_dict *tab)
{
	ft_strcpy(tab[24].nbr, "60");
	ft_strcpy(tab[25].nbr, "70");
	ft_strcpy(tab[26].nbr, "80");
	ft_strcpy(tab[27].nbr, "90");
	ft_strcpy(tab[28].nbr, "100");
	ft_strcpy(tab[29].nbr, "1000");
	ft_strcpy(tab[30].nbr, "1000000");
	ft_strcpy(tab[31].nbr, "1000000000");
	ft_strcpy(tab[32].nbr, "1000000000000");
	ft_strcpy(tab[33].nbr, "1000000000000000");
	ft_strcpy(tab[34].nbr, "1000000000000000000");
	ft_strcpy(tab[35].nbr, "1000000000000000000000");
	ft_strcpy(tab[36].nbr, "1000000000000000000000000");
	ft_strcpy(tab[37].nbr, "1000000000000000000000000000");
	ft_strcpy(tab[38].nbr, "1000000000000000000000000000000");
	ft_strcpy(tab[39].nbr, "1000000000000000000000000000000000");
	ft_strcpy(tab[40].nbr, "1000000000000000000000000000000000000");
	return (tab);
}

t_dict	*cpynbr(t_dict *tab)
{
	ft_strcpy(tab[0].nbr, "0");
	ft_strcpy(tab[1].nbr, "1");
	ft_strcpy(tab[2].nbr, "2");
	ft_strcpy(tab[3].nbr, "3");
	ft_strcpy(tab[4].nbr, "4");
	ft_strcpy(tab[5].nbr, "5");
	ft_strcpy(tab[6].nbr, "6");
	ft_strcpy(tab[7].nbr, "7");
	ft_strcpy(tab[8].nbr, "8");
	ft_strcpy(tab[9].nbr, "9");
	ft_strcpy(tab[10].nbr, "10");
	ft_strcpy(tab[11].nbr, "11");
	ft_strcpy(tab[12].nbr, "12");
	ft_strcpy(tab[13].nbr, "13");
	ft_strcpy(tab[14].nbr, "14");
	ft_strcpy(tab[15].nbr, "15");
	ft_strcpy(tab[16].nbr, "16");
	ft_strcpy(tab[17].nbr, "17");
	ft_strcpy(tab[18].nbr, "18");
	ft_strcpy(tab[19].nbr, "19");
	ft_strcpy(tab[20].nbr, "20");
	ft_strcpy(tab[21].nbr, "30");
	ft_strcpy(tab[22].nbr, "40");
	ft_strcpy(tab[23].nbr, "50");
	return (cpynbr2(tab));
}
