/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 07:23:17 by kreys             #+#    #+#             */
/*   Updated: 2023/11/01 19:23:12 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	count;

	count = 0;
	while (size != 1 && size > 0 && *src)
	{
		size--;
		*dest = *src;
		dest++;
		src++;
		count++;
	}
	while (*src)
	{
		src++;
		count++;
	}
	if (size <= 0)
		return (count);
	if (*dest)
		*dest = '\0';
	return (count);
}
