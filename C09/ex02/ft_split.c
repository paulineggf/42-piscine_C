/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:17:44 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/19 19:55:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strchr(char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_cmp_letter(char *str, char *charset, int *words)
{
	int		i;
	int		j;
	int		let;

	i = 0;
	j = 0;
	while (str[i])
	{
		let = 0;
		while ((ft_strchr(charset, str[i])) && str[i])
			i++;
		while ((!ft_strchr(charset, str[i])) && str[i])
		{
			let++;
			i++;
		}
		words[j] = let;
		j++;
	}
}

int		*ft_cmp_words(char *str, char *charset, int *cmp)
{
	int		i;
	int		*words;

	i = 0;
	while (str[i])
	{
		while ((ft_strchr(charset, str[i])) && str[i])
			i++;
		while ((!ft_strchr(charset, str[i]) && str[i]))
			i++;
		if (!(ft_strchr(charset, str[i - 1])))
			*cmp += 1;
	}
	if (!(words = (int*)malloc(sizeof(int) * *cmp)))
		return (NULL);
	return (words);
}

char	**ft_split_words(char **split, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (split[i] != 0)
	{
		j = 0;
		while ((ft_strchr(charset, str[k]) && str[k]))
			k++;
		while ((!ft_strchr(charset, str[k]) && str[k]))
		{
			split[i][j] = str[k];
			j++;
			k++;
		}
		split[i][j] = '\0';
		i++;
	}
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		cmp;
	int		*words;
	char	**split;

	i = 0;
	cmp = 0;
	words = ft_cmp_words(str, charset, &cmp);
	ft_cmp_letter(str, charset, words);
	if (!(split = (char**)malloc(sizeof(char*) * cmp + 1)))
		return (NULL);
	while (i < cmp)
	{
		if (!(split[i] = (char*)malloc(sizeof(char) * words[i] + 1)))
			return (NULL);
		i++;
	}
	split[i] = 0;
	split = ft_split_words(split, str, charset);
	return (split);
}
