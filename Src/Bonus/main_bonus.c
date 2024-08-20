/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:34 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/20 16:27:02 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first(char *argv[], int *pid, int fd[2])
{
	pid[0] = fork();
	if (pid[0] == -1)
		exit_error(0, NULL);
	if (pid[0] == 0)
		first_command(argv, fd);
}

static void	middle(int argc, char *argv[], int *pid, int fd[2])
{
	int	pid_i;

	pid_i = 1;
	while (pid_i < (argc - 4))
	{
		waitpid(pid[pid_i - 1], NULL, 0);
		pid[pid_i] = fork();
		if (pid[pid_i] == -1)
			exit_error(0, NULL);
		if (pid[pid_i] == 0)
			middle_command(argv[pid_i + 2], argv, argc, fd);
		pid_i++;
	}
}

static void	last(int argc, char *argv[], int *pid, int fd[2])
{
	waitpid(pid[argc - 5], NULL, 0);
	pid[argc - 4] = fork();
	if (pid[argc - 4] == -1)
		exit_error(0, NULL);
	if (pid[argc - 4] == 0)
		last_command(argv, argc, fd, O_R);
}

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	*pid;

	verify_args(argc, argv);
	if (pipe(fd) == -1)
		exit_error(0, NULL);
	pid = malloc(sizeof(int) * (argc - 4) + 1);
	if (!pid)
		exit_error(0, NULL);
	first(argv, pid, fd);
	middle(argc, argv, pid, fd);
	last(argc, argv, pid, fd);
	close(fd[0]);
	close(fd[1]);
	while (*pid)
		waitpid(*pid++, NULL, 0);
	return (0);
}
