/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:55:14 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/03 16:55:43 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->cmd_nb - 1)
	{
		if (pipe(all->pipe + 2 * i) < 0)
			parent_free(all);
		i++;
	}
}

void	close_pipes(t_all *all)
{
	int	i;

	i = 0;
	while (i < (all->pipe_nb))
	{
		close(all->pipe[i++]);
	}
}
