/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 07:01:46 by kreys             #+#    #+#             */
/*   Updated: 2023/10/30 16:41:39 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
	{
		symbol++;
	}
	else if (symbol >= 'a' && symbol <= 'z')
	{
		symbol++;
	}
	else
	{
		return (0);
	}
	return (1);
}
