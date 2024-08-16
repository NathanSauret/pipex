/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:20:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/16 18:28:32 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Src/pipex.h"

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	verify_args(argc, argv);
	if (pipe(fd) == -1)
		exit_error(0, NULL);
	pid1 = fork();
	if (pid1 == -1)
		exit_error(0, NULL);
	if (pid1 == 0)
		command_to_pipe(argv, fd);
	pid2 = fork();
	if (pid2 == -1)
		exit_error(0, NULL);
	if (pid2 == 0)
		command_using_pipe(argv, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
