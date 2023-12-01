/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:46:16 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 15:17:02 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list		*my_list;

	my_list = lst;
	if (f == NULL)
		return ;
	while (my_list)
	{
		f(my_list->content);
		my_list = my_list->next;
	}
}
