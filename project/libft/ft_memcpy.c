/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 02:54:39 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			size;

	size = 0;
	if (!dst && !src)
		return (NULL);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (n > size)
	{
		str1[size] = str2[size];
		size++;
	}
	return (dst);
}
