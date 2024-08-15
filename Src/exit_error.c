/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:25:51 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/15 16:03:32 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// case_0 = general case
// case_1 = file or cmd problem


void	exit_error(int error_case, char *arg)
{
	if (error_case == 0)
		perror("Error\n");
	else if (error_case == 1)
		perror(arg);
	exit (1);
}
