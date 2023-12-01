/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:21:44 by kreys             #+#    #+#             */
/*   Updated: 2023/12/01 18:47:16 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	create_file(char *name)
{
	char	*str;
	int		file;

	file = open(name, O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (file == -1)
	{
		catch_error(CRFILE, NULL);
		return (-1);
	}
	str = get_next_line(0);
	while (str)
	{
		ft_printf("%s", file, str);
		free(str);
		str = get_next_line(0);
	}
	close(file);
	return (1);
}

void	write_in_file(t_prj *prj, char *name2)
{
	int		i;
	char	*str;

	i = 0;
	prj->file2 = open(name2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (prj->file2 == -1)
	{
		close(prj->file1);
		catch_error(NULL, name2);
	}
	dup2(prj->file2, prj->pipe[1]);
	str = get_next_line(prj->pipe[0]);
	while (str)
	{
		ft_printf("%s", prj->pipe[1], str);
		free(str);
		str = get_next_line(prj->pipe[0]);
	}
	close(prj->pipe[0]);
	close(prj->pipe[1]);
}
