/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:23:05 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/23 18:47:20 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDICT_H
# define LIBDICT_H

typedef struct		s_dict
{
	char	nbr[45];
	char	*let;
}					t_dict;

char				*ft_cpy_file(void);
char				*ft_strcat(char *dest, char *src);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strjoin_cat(char *str, char *buf);
char				*ft_strdup_rl(char *src);
char				*ft_strdup(char *src);
int					ft_strlen(char *str);
int					ft_isspace(char c);
int					ft_control_param(char *str);
void				ft_print_number(char *str, t_dict *tab);
int					ft_index(char *str, int len, t_dict *tab);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
void				ft_putstr(char *str);
t_dict				*ft_putstruct(char *str, t_dict *tab);
t_dict				*cpynbr(t_dict *tab);
t_dict				*cpynbr2(t_dict *tab);

#endif
