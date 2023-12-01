/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:46:16 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 07:00:56 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
		symbol -= 32;
	return (symbol);
}

// int main(void)
// {
// 	printf("%c -> %c\n", 'a', ft_toupper('a'));
// 	printf("%c -> %c\n", '2', ft_toupper('2'));
// 	printf("%c -> %c\n", 'd', ft_toupper('d'));
// 	printf("%c -> %c\n", 'A', ft_toupper('A'));
// }
