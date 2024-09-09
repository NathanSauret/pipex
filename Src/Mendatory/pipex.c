/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:11:51 by nathan            #+#    #+#             */
/*   Updated: 2024/09/09 15:10:48 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_to_pipe(char *argv[], char *envp[], int fd[2], int *pid)
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(argv[2], ' ');
	if (!args)
	{
		write(2, ": command not found\n", 21);
		exit_error(3, NULL, NULL, pid);
	}
	path = get_path(envp, args, pid);
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
	if (!args)
	{
		write(2, ": command not found\n", 21);
		exit_error(3, NULL, NULL, pid);
	}
	path = get_path(envp, args, pid);
	execve(path, args, envp);
	ft_freetabstr(args);
	close(fd_file);
}
