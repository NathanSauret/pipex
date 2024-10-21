/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:27:07 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/15 15:06:04 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_infile(char *argv[], t_all *all)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], all);
	else
	{
		all->infile = open(argv[1], O_RDONLY);
		if (all->infile < 0)
			perror(argv[1]);
	}
}

void	get_outfile(char *argv, t_all *all)
{
	if (all->here_doc)
		all->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		all->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (all->outfile < 0)
		exit_error(all, 1, argv);
}
