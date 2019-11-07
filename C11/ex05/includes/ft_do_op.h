/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:23:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/27 17:24:05 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

typedef struct		s_do_op
{
	char	str;
	void	(*ptr)(int, int);
}					t_do_op;

void				ft_plus(int nb1, int nb2);
void				ft_moins(int nb1, int nb2);
void				ft_div(int nb1, int nb2);
void				ft_mult(int nb1, int nb2);
void				ft_mod(int nb1, int nb2);
void				ft_putnbr(int nbr);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(char *str);

#endif
