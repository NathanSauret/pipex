/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:25:51 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/20 10:25:46 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// case_0 = general case
// case_1 = file or cmd problem
// case_2 = command not found

void	exit_error(int error_case, char *arg)
{
	if (error_case == 0)
		write(2, "Error\n", 7);
	else if (error_case == 1)
		perror(arg);
	else if (error_case == 2)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": command not found\n", 20);
		free(arg);
	}
	exit (1);
}
