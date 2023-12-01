/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:31 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 08:41:06 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = 0;
// 	i = 0;
// 	j = 0;
// 	if (s1 != 0 && set != 0)
// 	{
// 		i = 0;
// 		j = ft_strlen(s1);
// 		while (ft_strchr(set, s1[i]) && s1[i])
// 			i++;
// 		while (s1[j - 1] && ft_strchr(set, s1[j - 1] && j > i))
// 			j--;
// 		str = malloc(sizeof(char) * (j - i + 1));
// 		if (str)
// 			ft_strlcpy(str, &s1[i], j - i + 1);
// 	}
// 	return (str);
// }

static int
	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start_point;
	size_t	last_point;

	if (s1 == 0 || set == 0)
		return (NULL);
	start_point = 0;
	while (s1[start_point] && ft_char_in_set(s1[start_point], set))
		start_point++;
	last_point = ft_strlen(s1);
	while (last_point > start_point && ft_char_in_set(s1[last_point - 1], set))
		last_point--;
	str = (char *)malloc(sizeof(*s1) * (last_point - start_point + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start_point < last_point)
		str[i++] = s1[start_point++];
	str[i] = 0;
	return (str);
}
