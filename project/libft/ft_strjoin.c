/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:31 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 06:10:03 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*str;
// 	int		iteration_main;
// 	int		size;

// 	size = ft_strlen(s1) + ft_strlen(s2);
// 	printf("%d\n", size);
// 	iteration_main = 0;
// 	str = malloc(sizeof(char) * (size + 1));
// 	if (!str)
// 		return (NULL);
// 	str[size] = '\0';
// 	ft_memmove(&str[0], s1, ft_strlen(s1));
// 	ft_memmove(&str[ft_strlen(s1)], s2, ft_strlen(s2));
// 	return (str);
// }

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
