/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:31 by kreys             #+#    #+#             */
/*   Updated: 2023/10/30 19:39:01 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src1, int symbol, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *)src1;
	while (n > i)
	{
		if (src[i] == (unsigned char)symbol)
			return ((char *)src + i);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char src[50] = "123456789";
// 	char src1[50] = "123456789";

// 	printf("%s\n", memchr(src, '9', 9));
// 	printf("%s", ft_memchr(src, '9', 9));
// }
