/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:20:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/21 18:00:55 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_values(int argc, char *argv[], char *envp[], t_all *all)
{
	get_infile(argv, all);
	get_outfile(argv[argc - 1], all);
	all->cmd_nb = argc - 3 - all->here_doc;
	all->pipe_nb = 2 * (all->cmd_nb - 1);
	all->pipe = (int *)malloc(sizeof(int) * all->pipe_nb);
	if (!all->pipe)
		exit_error(all, 1, "Error: pipe");
	all->env_path = get_path(envp);
	all->cmd_paths = ft_split(all->env_path, ':');
	all->msi = -1;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_all	all;

	if (!check_args(argc, argv, &all))
		exit_error(NULL, 0, "Error: wrong arguments");
	set_values(argc, argv, envp, &all);
	create_pipes(&all);
	pipex(&all, argv, envp);
	close_pipes(&all);
	waitpid(-1, NULL, 0);
	parent_free(&all);
	return (0);
}
