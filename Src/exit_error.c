/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:25:51 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/17 01:06:16 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
