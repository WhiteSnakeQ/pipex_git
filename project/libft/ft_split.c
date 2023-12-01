/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/11/29 14:50:03 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(char const *s, char c)
{
	size_t	counts;

	if (!s || !*s)
		return (0);
	counts = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counts++;
		while (*s != c && *s)
			s++;
	}
	return (counts);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	lenss;
	int		i;

	str = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				lenss = ft_strlen(s);
			else
				lenss = ft_strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, lenss);
			s += lenss;
		}
	}
	str[i] = NULL;
	return (str);
}
