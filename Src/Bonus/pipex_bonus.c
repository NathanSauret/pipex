/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:11:51 by nathan            #+#    #+#             */
/*   Updated: 2024/08/20 12:34:57 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_command(char *argv[], int fd[2])
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(argv[2], ' ');
	path = ft_strjoin("/bin/", args[0]);
	fd_file = open(argv[1], O_RDONLY);
	dup2(fd_file, 0);
	if (execve(path, args, NULL) == -1)
	{
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 20);
		ft_freetabstr(args);
		free(args);
		free(path);
		close(fd_file);
		exit(1);
	}
	ft_freetabstr(args);
	free(path);
	close(fd_file);
}

void	middle_command(char *arg, char *argv[], int argc, int fd[2])
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	fd_file = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	dup2(fd_file, 1);
	args = ft_split(arg, ' ');
	path = ft_strjoin("/bin/", args[0]);
	if (execve(path, args, NULL) == -1)
	{
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 20);
		ft_freetabstr(args);
		free(args);
		free(path);
		exit(1);
	}
	ft_freetabstr(args);
	free(path);
}

void	last_command(char *argv[], int argc, int fd[2], int write_way)
{
	char	*path;
	char	**args;
	int		fd_file;

	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(argv[argc - 2], ' ');
	path = ft_strjoin("/bin/", args[0]);
	fd_file = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	dup2(fd_file, 1);
	if (execve(path, args, NULL) == -1)
	{
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 20);
		ft_freetabstr(args);
		free(args);
		free(path);
		close(fd_file);
		exit(1);
	}
	ft_freetabstr(args);
	free(path);
	close(fd_file);
}
