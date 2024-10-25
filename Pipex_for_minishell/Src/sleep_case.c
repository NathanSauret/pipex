/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:06:28 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/25 16:00:41 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmds(t_all *all)
{
	if (all->cmd_args)
	{
		ft_freetabstr(all->cmd_args);
		free(all->cmd_args);
	}
}

static void	get_to_bed(t_all *all, char **argv, char **envp)
{
	int		idx;
	char	**cmd;

	cmd = ft_calloc(3, sizeof(char *));
	if (!cmd)
		return ;
	cmd[0] = "sleep";
	cmd[1] = "0";
	idx = 0;
	while (idx < all->cmd_nb)
	{
		all->cmd_args = ft_split(argv[2 + all->here_doc + idx], ' ');
		if (all->cmd_args
			&& !ft_strncmp(all->cmd_args[0], "sleep", 5)
			&& ft_atoi(all->cmd_args[1]) > ft_atoi(cmd[1]))
			cmd[1] = ft_strdup(all->cmd_args[1]);
		free_cmds(all);
		idx++;
	}
	if (ft_atoi(cmd[1]) > 0)
		execve("/usr/bin/sleep", cmd, envp);
	free(cmd);
}

int	sleep_case(t_all *all, char **argv, char **envp)
{
	get_to_bed(all, argv, envp);
	return (1);
}
