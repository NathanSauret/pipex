/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:34:03 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/03 17:38:42 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	end_here_doc(int fd, char *buffer, t_all *all)
{
	get_next_line(fd, 0);
	free(buffer);
	close(fd);
	all->infile = open(".heredoc", O_RDONLY);
	if (all->infile < 0)
	{
		unlink(".heredoc");
		exit_error(1, "here_doc");
	}
}

void	here_doc(char *argv, t_all *all)
{
	int		fd;
	char	*buffer;

	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (fd < 0)
		exit_error(1, ".here_doc");
	while (1)
	{
		write(1, "heredoc> ", 9);
		buffer = get_next_line(0, 1);
		if (buffer == NULL)
		{
			get_next_line(0, 0);
			exit(1);
		}
		if (!ft_strncmp(argv, buffer, ft_strlen(argv)))
			break ;
		write(fd, buffer, ft_strlen(buffer) - 1);
		write(fd, "\n", 1);
		free(buffer);
	}
	end_here_doc(fd, buffer, all);
}
