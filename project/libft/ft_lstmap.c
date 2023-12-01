/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:31 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 15:45:31 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *))
{
	t_list		*my_list;
	t_list		*return_l;	

	if (!f || !del || !lst)
		return (NULL);
	my_list = ft_lstnew(f(lst->content));
	if (my_list == NULL)
		return (NULL);
	return_l = my_list;
	lst = lst->next;
	while (lst)
	{
		my_list->next = ft_lstnew(f(lst->content));
		if (my_list->next == NULL)
		{
			ft_lstclear(&return_l, del);
			return (NULL);
		}
		my_list = my_list->next;
		lst = lst->next;
	}
	my_list->next = NULL;
	return (return_l);
}
