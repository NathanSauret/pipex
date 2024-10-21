/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:27:23 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/18 17:28:21 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "Utils/utils.h"

typedef struct s_all
{
	int		here_doc;
	int		infile;
	int		outfile;
	int		cmd_nb;
	int		pipe_nb;
	int		*pipe;
	char	*env_path;
	char	**cmd_paths;
	int		idx;
	pid_t	pid;
	char	**cmd_args;
	char	*cmd;
}	t_all;

// check_args.c
int		check_args(int argc, char *argv[], t_all *all);

// exit_error.c
void	exit_error(t_all *all, int error_case, char *arg);

// free.c
void	parent_free(t_all *all);
void	child_free(t_all *all);
void	pipe_free(t_all *all);

// get_files.c
void	get_infile(char *argv[], t_all *all);
void	get_outfile(char *argv, t_all *all);

// get_path.c
char	*get_path(char **envp);

// here_doc.c
void	here_doc(char *argv, t_all *all);

// pipes_utils.c
void	create_pipes(t_all *all);
void	close_pipes(t_all *all);

// pipex.c
void	pipex(t_all *all, char **argv, char **envp);

// sleep_case.c
int		sleep_case(t_all *all, char **argv);

#endif