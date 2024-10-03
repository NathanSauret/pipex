/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:11:51 by nathan            #+#    #+#             */
/*   Updated: 2024/10/03 18:01:44 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

static void	my_dup(int first, int second)
{
	dup2(first, 0);
	dup2(second, 1);
}

static void	child(t_all *all, char **argv, char **envp)
{
	all->pid = fork();
	if (!all->pid)
	{
		if (all->idx == 0)
			my_dup(all->infile, all->pipe[1]);
		else if (all->idx == all->cmd_nb - 1)
			my_dup(all->pipe[2 * all->idx - 2], all->outfile);
		else
			my_dup(all->pipe[2 * all->idx - 2], all->pipe[2 * all->idx + 1]);
		close_pipes(all);
		all->cmd_args = ft_split(argv[2 + all->here_doc + all->idx], ' ');
		all->cmd = get_cmd(all->cmd_paths, all->cmd_args[0]);
		if (!all->cmd)
		{
			write(2, all->cmd_args[0], ft_strlen(all->cmd_args[0]));
			write(2, ": command not found\n", 21);
			child_free(all);
			ft_freetabstr(all->cmd_paths);
			free(all->cmd_paths);
			free(all->pipe);
			exit(1);
		}
		execve(all->cmd, all->cmd_args, envp);
	}
}

void	pipex(t_all *all, char *argv[], char *envp[])
{
	all->idx = -1;
	while (++(all->idx) < all->cmd_nb)
		child(all, argv, envp);
}
