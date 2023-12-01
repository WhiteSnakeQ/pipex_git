/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:18:50 by kreys             #+#    #+#             */
/*   Updated: 2023/12/01 17:52:10 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	took_env(t_prj *prj, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
			break ;
		i++;
	}
	prj->paths = ft_split(&env[i][5], ':');
}

void	init_prj(t_prj *prj, char **env)
{
	prj->file_name = NULL;
	prj->list_cmd = NULL;
	prj->pipe = malloc(sizeof(int) * 2);
	if (!prj->pipe)
		catch_error(MALLOCFAIL, NULL);
	prj->error = 0;
	prj->manual = 0;
	took_env(prj, env);
}

t_cmd	*init_cmd(char **text)
{
	t_cmd	*cmd;

	if (!text)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->next = NULL;
	cmd->cmd = text;
	return (cmd);
}

char	**create_strs(t_text *text, int size)
{
	char	**strs;
	t_text	*clean;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (size + 1));
	if (!strs)
		catch_error(MALLOCFAIL, NULL);
	while (i < size)
	{
		strs[i++] = text->str;
		clean = text;
		text = text->next;
		free(clean);
	}
	strs[i] = NULL;
	return (strs);
}

t_text	*new_text(char *str)
{
	t_text	*text;

	if (!str)
		return (NULL);
	text = malloc(sizeof(t_text));
	if (!text)
		catch_error(MALLOCFAIL, NULL);
	text->str = ft_strdup(str);
	text->next = NULL;
	return (text);
}
