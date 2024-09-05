/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:20:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/05 18:04:55 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first(char *argv[], char *envp[], int *pid, int fd[2])
{
	pid[0] = fork();
	if (pid[0] == -1)
		exit_error(0, NULL, NULL, pid);
	if (pid[0] == 0)
		command_to_pipe(argv, envp, fd, pid);
	if (waitpid(pid[0], NULL, 0) == -1)
		exit_error(0, NULL, NULL, pid);
}

static void	last(char *argv[], char *envp[], int *pid, int fd[2])
{
	pid[1] = fork();
	if (pid[1] == -1)
		exit_error(0, NULL, NULL, pid);
	if (pid[1] == 0)
		command_using_pipe(argv, envp, fd, pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	*pid;

	if (argc != 5)
		exit_error(0, NULL, NULL, NULL);
	if (pipe(fd) == -1)
		exit_error(0, NULL, NULL, NULL);
	pid = malloc(sizeof(int) * 2 + 1);
	if (!pid)
		exit_error(0, NULL, NULL, NULL);
	if (access(argv[1], F_OK) == 0 && access(argv[1], R_OK) == 0)
		first(argv, envp, pid, fd);
	else
		perror(argv[1]);
	last(argv, envp, pid, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[1], NULL, 0);
	free(pid);
	return (0);
}
