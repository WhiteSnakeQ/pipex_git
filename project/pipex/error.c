/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:04:45 by kreys             #+#    #+#             */
/*   Updated: 2023/12/01 17:42:59 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	catch_error(char *error, char *error2)
{
	if (error)
	{
		ft_printf("pipex: ", 2);
		ft_printf("%s", 2, error);
	}
	else if (error2)
		perror(ft_strjoin("pipex: ", error2));
	else
		perror("pipex");
	if (error && error2)
		exit(EXIT_FAILURE);
}
