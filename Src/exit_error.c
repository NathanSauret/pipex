/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:25:51 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/03 17:44:15 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// case_-1 = problem without msg
// case_0 = with message
// case_1 = with perror
// case_2 = command not found

// static void	permission_denied(int error_case, char **args)

void	exit_error(int error_case, char *arg)
{
	if (error_case == 0)
	{
		write(2, arg, ft_strlen(arg));
		write(2, "\n", 1);
	}
	else if (error_case == 1)
		perror(arg);
	else if (error_case == 2)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": command not found\n", 21);
		free(arg);
	}
	exit (1);
}
