/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:06:26 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 02:41:27 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checking_string( const char *str1, const char *str2, size_t iteration)
{
	size_t	internal_i;

	internal_i = 0;
	while (str2[internal_i])
	{
		if (str1[iteration++] != str2[internal_i++])
			return (0);
	}
	return (1);
}

char	*ft_strnstr( const char *str, const char *to_find, size_t n)
{
	size_t		iteration;
	size_t		size_f;

	iteration = 0;
	if (!*to_find)
		return ((char *)str);
	if (n <= 0)
		return (NULL);
	size_f = 0;
	while (to_find[size_f])
		size_f++;
	while (str[iteration] && n >= iteration + size_f)
	{
		if (str[iteration] == to_find[0])
			if (checking_string(str, to_find, iteration) == 1)
				return ((char *)&str[iteration]);
		iteration++;
	}
	return (NULL);
}
