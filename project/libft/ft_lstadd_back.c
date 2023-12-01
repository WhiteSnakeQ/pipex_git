/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:31 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 14:08:47 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*my_list;

	if (lst == (void *)0)
		return ;
	my_list = ft_lstlast(*lst);
	if (my_list == NULL)
		*lst = new;
	else
		my_list->next = new;
}
