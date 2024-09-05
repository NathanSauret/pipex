/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:11:51 by nathan            #+#    #+#             */
/*   Updated: 2024/09/05 18:53:21 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static void	free_paths(char **paths)
{
	ft_freetabstr(paths);
	free(paths);
}


static char	*get_path(char *envp[], char **args, int *pid)
{
	char	**paths;
	char	*path;
	int		i;

	path = NULL;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], args[0]);
		if (!paths[i])
			return (free_paths(paths), NULL);
		if (access(paths[i], 0) == 0)
		{
			path = ft_strdup(paths[i]);
			return (free_paths(paths), path);
		}
		i++;
	}
	return (free_paths(paths), exit_error(2, path, args, pid), NULL);
}

void	command_to_pipe(char *argv[], char *envp[], int fd[2], int *pid)
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(argv[2], ' ');
	path = NULL;
	if (!char_in_str('/', args[0]))
	{
		if (envp && envp[0])
			path = get_path(envp, args, pid);
	}
	else if (access(args[0], 0) == 0)
		path = args[0];
	else
		exit_error(2, path, args, pid);
	fd_file = open(argv[1], O_RDONLY);
	dup2(fd_file, 0);
	execve(path, args, envp);
	ft_freetabstr(args);
	close(fd_file);
}

void	command_using_pipe(char *argv[], char *envp[], int fd[2], int *pid)
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	fd_file = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	dup2(fd_file, 1);
	args = ft_split(argv[3], ' ');
	path = NULL;
	if (!char_in_str('/', args[0]))
	{
		if (envp && envp[0])
			path = get_path(envp, args, pid);
	}
	else if (access(args[0], 0) == 0)
		path = args[0];
	else
		exit_error(2, path, args, pid);
	execve(path, args, envp);
	ft_freetabstr(args);
	close(fd_file);
}
