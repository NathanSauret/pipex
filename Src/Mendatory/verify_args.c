/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:28:53 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/22 15:00:02 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	verify_args(int argc, char *argv[])
{
	if (argc != 5)
		exit_error(0, NULL, NULL, NULL);
	if (access(argv[1], F_OK) == -1)
		exit_error(1, NULL, NULL, NULL);
}
