/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/10/30 16:42:01 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				size;

	size = 0;
	str = (unsigned char *)b;
	while (len-- > 0)
	{
		str[size++] = c;
	}
	return (b);
}

// int	main(void)
// {
// 	char	str[50] = "GeeksForGeeks is for programming geeks.";
// 	char	str1[50] = "GeeksForGeeks is for programming geeks.";

// 	printf("\nBefore memset(): %s\n", str);
// 	ft_memset(str, '.', 5 * sizeof(int));
// 	memset(str1, '.', 5 * sizeof(int));
// 	printf("After memset():  %s\n", str);
// 	printf("After memset():  %s\n", str1);
// 	return (0);
// }
