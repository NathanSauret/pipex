/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:56:46 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/15 15:18:25 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_free(t_all *all)
{
	int	i;

	i = 0;
	close(all->infile);
	close(all->outfile);
	if (all->here_doc)
		unlink(".heredoc_tmp");
	while (all->cmd_paths && all->cmd_paths[i])
	{
		free(all->cmd_paths[i]);
		i++;
	}
	free(all->cmd_paths);
	free(all->pipe);
}

void	child_free(t_all *all)
{
	int	i;

	i = 0;
	while (all->cmd_args[i])
	{
		free(all->cmd_args[i]);
		i++;
	}
	free(all->cmd_args);
	free(all->cmd);
	if (all->infile)
		close(all->infile);
	if (all->outfile)
		close(all->outfile);
}

void	pipe_free(t_all *all)
{
	if (all->here_doc)
		unlink(".heredoc_tmp");
	free(all->pipe);
	exit_error(all, 0, "Environment");
}
