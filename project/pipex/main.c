/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:58:17 by kreys             #+#    #+#             */
/*   Updated: 2023/12/02 10:11:29 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	size_calc(t_text *text)
{
	int	i;

	i = 0;
	while (text)
	{
		text = text->next;
		i++;
	}
	return (i);
}

char	**add_par(char **strs, char *str)
{
	char	**ret;
	int		i;
	int		d;

	d = 0;
	i = 0;
	while (strs[i])
		i++;
	ret = malloc (sizeof(char *) * (i + 2));
	i = 0;
	while (strs[i])
		ret[d++] = strs[i++];
	ret[d++] = str;
	ret[d] = NULL;
	free(strs);
	return (ret);
}

void	pipex(t_prj *prj, char **env, int i)
{
	pid_t	pid;

	if (pipe(prj->pipe) == -1)
		catch_error(NULL, NULL);
	pid = fork();
	if (pid == -1)
		catch_error(NULL, NULL);
	if (pid == 0)
	{
		dup2(prj->pipe[1], STDOUT_FILENO);
		if (i == 1 && prj->file1 != -1)
			dup2(prj->file1, STDIN_FILENO);
		else if (i == 1 && prj->file1 == -1)
		{
			clean_all(&prj);
			exit(EXIT_FAILURE);
		}
		close(prj->pipe[0]);
		execve(prj->list_cmd->name, prj->list_cmd->cmd, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(prj->pipe[1]);
		dup2(prj->pipe[0], STDIN_FILENO);
		remove_cmd(prj);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_prj	*prj;
	int		i;

	i = 0;
	if (argc <= 4)
		return (0);
	prj = malloc(sizeof(t_prj));
	if (!prj)
		catch_error(MALLOCFAIL, NULL);
	init_prj(prj, env);
	parse_file_name(prj, argv[1]);
	parse_cmd(prj, argv, argc);
	i += prj->skip;
	while (argc - 3 > i++)
	{
		if (!prj->list_cmd)
			break ;
		pipex(prj, env, i);
		if (i == 1 && prj->manual == 1)
			unlink(prj->file_name);
	}
	write_in_file(prj, argv[argc - 1]);
	clean_all(&prj);
	return (0);
}
