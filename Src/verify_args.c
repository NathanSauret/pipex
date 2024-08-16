/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:28:53 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/16 18:16:28 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	verify_args(int argc, char *argv[])
{
	if (argc != 5)
		exit_error(0, NULL);
	if (access(argv[1], F_OK) == -1)
		exit_error(1, argv[1]);
}
