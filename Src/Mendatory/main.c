/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:20:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/22 16:33:08 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first(char *argv[], char **envp, int *pid, int fd[2])
{
	pid[0] = fork();
	if (pid[0] == -1)
		exit_error(0, NULL, NULL, pid);
	if (pid[0] == 0)
		command_to_pipe(argv, envp, fd, pid);
}

static void	last(char *argv[], char **envp, int *pid, int fd[2])
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

	verify_args(argc, argv);
	if (pipe(fd) == -1)
		exit_error(0, NULL, NULL, NULL);
	pid = malloc(sizeof(int) * 2 + 1);
	if (!pid)
		exit_error(0, NULL, NULL, NULL);
	first(argv, envp, pid, fd);
	last(argv, envp, pid, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	free(pid);
	return (0);
}
