/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:06:26 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 02:37:48 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
// {
// 	int				i;
// 	int				i2;
// 	unsigned int	to_ret;
// 	int				size1;

// 	i = ft_strlen(dest);
// 	to_ret = i;
// 	if (to_ret > size)
// 		to_ret = size;
// 	i2 = 0;
// 	size1 = size - to_ret;
// 	while (src != NULL && src[i2] && size1 - 1 > 0)
// 	{
// 		size1--;
// 		dest[i++] = src[i2++];
// 	}
// 	dest[i] = '\0';
// 	return (to_ret + ft_strlen(src));
// }

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dest == NULL)
		dest_len = 0;
	else
		dest_len = ft_strlen(dest);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char dest[0] = "";
// 	char dest1[0] = "";

// 	printf("%d -- %s\n", ft_strlcat(dest, 0, 0), dest);
// 	printf("%ld -- %s", strlcat(dest1, 0, 0), dest1);
// }
