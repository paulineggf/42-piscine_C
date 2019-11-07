/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:26:03 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/26 14:38:09 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_bsq
{
	int		x;
	int		y;
	int		size;
	int		max_y;
	long	max_x;
	char	obs;
	char	vide;
	char	remp;
	int		size_params;
}				t_bsq;

int				ft_plus(int lft, int up, int lftup);
void			ft_algo(int *l1, int *l2, t_bsq *res, int x);
void			ft_putchar(char c);
char			*ft_strcat(char *dest, char *src);
char			*ft_strjoin_cat(char *str, char *buf);
char			*ft_strcpy(char *dest, char *src);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			*ft_params_line(char *argv, t_bsq *par);
int				ft_define_params(char *params, t_bsq *par);
int				ft_do_line(char *argv, t_bsq *par);
int				ft_if_single_line(char *argv, t_bsq *par);
int				ft_entre_standard(void);
int				ft_while_file(char *argv);
int				ft_search_square(int *frst_line, int *sd_line,
				t_bsq *par, int fd);
void			ft_fill_sd_line(char *buf, int *sd_line, t_bsq *par, int *i);
int				ft_print_map(t_bsq *res, char *argv);

#endif
