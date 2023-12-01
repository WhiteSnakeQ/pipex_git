/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 02:19:30 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	s;

	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		s = n;
		while (s-- > 0)
			((unsigned char *)dst)[s] = ((unsigned char *)src)[s];
	}
	else
	{
		s = 0;
		while (s < n)
		{
			((unsigned char *)dst)[s] = ((unsigned char *)src)[s];
			s++;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str[40] = "GeeksForGeeks is for programming geeks.";
// 	char	str1[40] = "GeeksForGeeks is for programming geeks.";
// 	char	dst[50] = "123456789012345678901234567890";

// 	printf("\nBefore memset(): %s\n", str);
// 	ft_memmove(str, dst, 30 * sizeof(char));
// 	memmove(str1, dst, 30 * sizeof(char));
// 	printf("After memset - 1():  %s\n", str);
// 	printf("After memset - 2():  %s\n", str1);
// 	return (0);
// }

// char message2[60] = "Hi oleg, How are you today";
// char temp[60];

// int main(int argc, char const *argv[])
// {
//     strcpy(temp, message2);
//     printf("\n\nOriginal message: %s", temp);
//     memmove(temp, temp + 1, 10);
//     printf("\nAfter memcpy() without overlap:\t%s", temp);
//     strcpy(temp, message2);
//     memmove(temp + 6, temp + 4, 10);
//     printf("\nAfter memcpy() with overlap:\t%s", temp);

//     strcpy(temp, message2);
//     printf("\n\nOriginal message: %s", temp);
//     ft_memmove(temp, temp + 1, 10);
//     printf("\nAfter memmove() without overlap:\t%s", temp);
//     strcpy(temp, message2);
//     ft_memmove(temp + 6, temp + 4, 10);
//     printf("\nAfter memmove() with overlap:\t%s\n", temp);

// 	return 0;
// }
