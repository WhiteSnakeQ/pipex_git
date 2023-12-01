/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:04:45 by kreys             #+#    #+#             */
/*   Updated: 2023/12/01 20:09:20 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	catch_error(char *error, char *error2)
{
	char	*str;

	if (error)
	{
		ft_printf("pipex: ", 2);
		ft_printf("%s", 2, error);
	}
	else if (error2)
	{
		str = ft_strjoin("pipex: ", error2);
		perror(str);
		free(str);
	}
	else
		perror("pipex");
	if (error && error2)
		exit(EXIT_FAILURE);
}
