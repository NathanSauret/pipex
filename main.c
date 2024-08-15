/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:20:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/15 16:07:39 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Src/pipex.h"

void	exec_command(char *args[4])
{

}

int	main(int argc, char *argv[])
{
	char	*args[4];

	verify_args(argc, argv);
	args[0] = argv[1];
	args[1] = argv[2];
	args[2] = argv[3];
	args[3] = argv[4];

	ft_printf("file1: %s\n", args[0]);
	ft_printf("cmd1: %s\n", args[1]);
	ft_printf("cmd2: %s\n", args[2]);
	ft_printf("file2: %s\n\n", args[3]);

	return (0);
}
