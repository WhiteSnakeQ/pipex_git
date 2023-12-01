/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 07:23:17 by kreys             #+#    #+#             */
/*   Updated: 2023/11/01 19:29:52 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	size_ful;
	void	*obj;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	size_ful = count * size;
	obj = malloc(sizeof(char) * (size_ful));
	if (obj == NULL)
		return (NULL);
	else
		ft_bzero(obj, size_ful);
	return (obj);
}
