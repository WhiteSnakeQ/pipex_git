/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:31 by kreys             #+#    #+#             */
/*   Updated: 2023/10/30 20:32:31 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *src, int symbol)
{
	int	i;
	int	b;

	i = 0;
	b = -2;
	if (symbol == '\0')
		return ((char *)src + ft_strlen(src));
	while (src[i])
	{
		if (src[i] == (char)symbol)
			b = i;
		i++;
	}
	if (b < 0)
		return (NULL);
	return ((char *)src + b);
}

// int	main(void)
// {
// 	char src[50] = "123456789";
// 	char src1[50] = "123456789";

// 	printf("%s\n", strrchr(src, 'c'));
// 	printf("%s", ft_strrchr(src, 'c'));
// }
