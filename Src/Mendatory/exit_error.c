/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:25:51 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/09 15:06:39 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// case_0 = general case
// case_1 = file or cmd problem
// case_2 = command not found
// case_3 = problem without msg

// static void	permission_denied(int error_case, char **args)

void	exit_error(int error_case, char *arg, char **args, int *pid)
{
	if (error_case == 0)
		write(2, "Error\n", 7);
	else if (error_case == 1)
		perror(arg);
	else if (error_case == 2)
	{
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 21);
	}
	if (arg)
		free(arg);
	if (args)
	{
		ft_freetabstr(args);
		free(args);
	}
	if (pid)
		free(pid);
	exit (1);
}
