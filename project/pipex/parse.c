/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:28:56 by kreys             #+#    #+#             */
/*   Updated: 2023/12/01 20:07:14 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*get_path(char *str, char **paths)
{
	int		i;
	char	*cheack;
	char	*midl;

	i = 0;
	while (paths[i])
	{
		cheack = ft_strjoin(paths[i], "/");
		midl = ft_strjoin(cheack, str);
		free(cheack);
		cheack = midl;
		if (access(cheack, X_OK) == 0)
			return (cheack);
		free(cheack);
		i++;
	}
	return (NULL);
}

t_cmd	*lstlast(t_cmd *lst)
{
	t_cmd		*my_list;

	my_list = lst;
	if (my_list == (void *)0)
		return (0);
	while (my_list->next)
		my_list = my_list->next;
	return (my_list);
}

void	lstadd_back(t_cmd **lst, t_cmd *new, t_prj *prj)
{
	t_cmd	*my_list;

	if (!new)
		return ;
	new->name = get_path(new->cmd[0], prj->paths);
	if (!new->name)
	{
		clean_cmd(&new, 1);
		return ;
	}
	if (lst == (void *)0)
		return ;
	my_list = lstlast(*lst);
	if (my_list == NULL)
		*lst = new;
	else
		my_list->next = new;
}

void	parse_file_name(t_prj *prj, char *name1)
{
	if (ft_strncmp("here_doc", name1, 8) == 0)
	{
		if (create_file(name1) == 1)
			prj->manual = 1;
	}
	prj->file1 = open(name1, O_RDONLY);
	if (prj->file1 == -1)
		catch_error(NULL, name1);
	prj->file_name = ft_strdup(name1);
}

void	parse_cmd(t_prj *prj, char **argv, int size)
{
	t_cmd	*cmd;
	int		i;

	i = 2;
	cmd = NULL;
	while (!cmd && i < size - 1)
	{
		cmd = init_cmd(ft_split(argv[i++], ' '));
		if (!cmd)
			continue ;
		cmd->name = get_path(cmd->cmd[0], prj->paths);
		if (!cmd->name)
		{
			ft_printf("pipex: %s: %s", 2, cmd->cmd[0], NCMM);
			clean_cmd(&cmd, 1);
			cmd = NULL;
		}
	}
	prj->list_cmd = cmd;
	while (i < size - 1)
		lstadd_back(&cmd, init_cmd(ft_split(argv[i++], ' ')), prj);
}
