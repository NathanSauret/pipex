/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:11:51 by nathan            #+#    #+#             */
/*   Updated: 2024/08/20 16:26:16 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **envp, char *command)
{
	char	**paths;
	char	*path;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	while (*paths)
	{
		*paths = ft_strjoin(*paths, "/");
		*paths = ft_strjoin(*paths, command);
		if (access(*paths, 0) == 0)
		{
			path = ft_strdup(*paths);
			ft_freetabstr(paths);
			return (path);
		}
		paths++;
	}
	ft_freetabstr(paths);
	return (NULL);
}

void	command_to_pipe(char *argv[], char **envp, int fd[2], int *pid)
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(argv[2], ' ');
	path = get_path(envp, args[0]);
	fd_file = open(argv[1], O_RDONLY);
	dup2(fd_file, 0);
	if (execve(path, args, envp) == -1)
	{
		close(fd_file);
		exit_error(2, NULL, args, pid);
	}
	ft_freetabstr(args);
	close(fd_file);
}

void	command_using_pipe(char *argv[], char **envp, int fd[2], int *pid)
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(argv[3], ' ');
	path = get_path(envp, args[0]);
	fd_file = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	dup2(fd_file, 1);
	if (execve(path, args, envp) == -1)
	{
		free(path);
		close(fd_file);
		exit_error(2, NULL, args, pid);
	}
	free(path);
	ft_freetabstr(args);
	close(fd_file);
}
