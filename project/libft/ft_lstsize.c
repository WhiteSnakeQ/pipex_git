/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:31 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 13:56:34 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list		*my_list;
	int			count;

	count = 1;
	my_list = lst;
	if (my_list == (void *)0)
		return (0);
	while (my_list->next)
	{
		count++;
		my_list = my_list->next;
	}
	return (count);
}
