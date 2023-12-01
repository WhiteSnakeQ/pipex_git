/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:46:16 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 07:01:04 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
		symbol += 32;
	return (symbol);
}

// int main(void)
// {
// 	printf("%c -> %c\n", 'a', ft_tolower('a'));
// 	printf("%c -> %c\n", '2', ft_tolower('2'));
// 	printf("%c -> %c\n", 'd', ft_tolower('d'));
// 	printf("%c -> %c\n", 'A', ft_tolower('A'));
// }
