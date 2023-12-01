/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:00:48 by kreys             #+#    #+#             */
/*   Updated: 2023/12/01 18:47:44 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "project_f.h"
# include "libft.h"
# include "get_next_line.h"

# define MALLOCFAIL "MALLOC FAIL\n"
# define PIPEFAIL "PIPE FAIL\n"
# define OPENERR "fileErr"
# define CRFILE "Create file failed"
typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_text
{
	char			*str;
	struct s_text	*next;
}					t_text;

typedef struct s_prj
{
	int				*pipe;
	int				file1;
	int				file2;
	int				manual;
	int				error;
	char			*file_name;
	char			**paths;
	struct s_cmd	*list_cmd;
}					t_prj;

//			Parse
void		parse_cmd(t_prj *prg, char **argv, int size);
void		parse_file_name(t_prj *prj, char *name1);
char		**create_strs(t_text *text, int size);
t_text		*new_text(char *str);

//			File_work
void		write_in_file(t_prj *prj, char *name2);
int			create_file(char *name);

//			Additional_func
void		catch_error(char *error, char *error2);
void		init_prj(t_prj *prj, char **env);
void		clean_cmd(t_cmd **cmd, int i);
void		remove_cmd(t_prj *prj);
void		clean_strs(t_prj *prj);
void		clean_all(t_prj **prj);
t_text		*ret_last(t_text *text);
t_cmd		*init_cmd(char **text);

#endif