/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:58:17 by kreys             #+#    #+#             */
/*   Updated: 2023/12/01 17:51:51 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	clean_cmd(t_cmd **cmd, int i)
{
	i = 0;
	if (!cmd || !*cmd)
		return ;
	while ((*cmd)->cmd[i])
		free((*cmd)->cmd[i++]);
	free(*cmd);
}

t_text	*ret_last(t_text *text)
{
	while (text->next)
		text = text->next;
	return (text);
}

void	remove_cmd(t_prj *prj)
{
	t_cmd	*next;

	next = prj->list_cmd->next;
	clean_cmd(&prj->list_cmd, 0);
	prj->list_cmd = next;
}

void	clean_strs(t_prj *prj)
{
	int	i;

	i = 0;
	while (prj->paths[i])
		free(prj->paths[i++]);
	if (prj->paths)
		free(prj->paths);
	prj->paths = NULL;
}

void	clean_all(t_prj **prj)
{
	if ((*prj)->file_name)
		free((*prj)->file_name);
	if ((*prj)->pipe)
		free((*prj)->pipe);
	clean_strs(*prj);
	while ((*prj)->list_cmd)
		remove_cmd(*prj);
	free(*prj);
}
