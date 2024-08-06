/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:20:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/06 17:28:39 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Src/pipex.h"

int	main(int argc, char *argv[])
{
	char	*file1_name;
	char	*cmd1_name;
	char	*cmd2_name;
	char	*file2_name;

	if (!verify_args(argc, argv))
		exit_error();
	file1_name = argv[1];
	cmd1_name = argv[2];
	cmd2_name = argv[3];
	file2_name = argv[4];

	ft_printf("file1: %s", file1_name);
	ft_printf("cmd1: %s", cmd1_name);
	ft_printf("cmd2: %s", cmd2_name);
	ft_printf("file2: %s", file2_name);
	return (0);
}
