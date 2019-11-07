/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:13:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/06/10 14:52:07 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 1;
	if (lowercase(str[0]))
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (lowercase(str[i]) && !(alphanum(str[i - 1])))
			str[i] = str[i] - 32;
		else if (uppercase(str[i]) && alphanum(str[i - 1]))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
