/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:06:28 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/21 18:01:23 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_complete_cmds(t_all *all, char ***complete_cmds)
{
	int	i;

	i = 0;
	while (i < all->cmd_nb)
		ft_freetabstr(complete_cmds[i++]);
}

static char	***get_cmds(t_all *all, char **argv, int idx)
{
	char	***complete_cmds;
	int		i;

	complete_cmds = malloc(sizeof(char **) * all->cmd_nb + 1);
	if (!complete_cmds)
		return (NULL);
	i = 0;
	while (i < all->cmd_nb)
		complete_cmds[i++] = ft_split(argv[2 + all->here_doc + ++idx], ' ');
	return (complete_cmds);
}

static void	get_to_bed(t_all *all, char ***cmds, char **envp)
{
	int		i;

	i = 0;
	while (i < all->cmd_nb)
	{
		if (!ft_strncmp(cmds[i][0], "sleep", 5)
			&& all->msi >= 0
			&& cmds[i][1]
			&& ft_atoi(cmds[i][1]) > ft_atoi(cmds[all->msi][1]))
			all->msi = i;
		else if (!ft_strncmp(cmds[i][0], "sleep", 5) && all->msi < 0)
			all->msi = i;
		i++;
	}
	if (all->msi >= 0)
		execve("/usr/bin/sleep", cmds[all->msi], envp);
}

int	sleep_case(t_all *all, char **argv, char **envp)
{
	int		idx;
	char	***complete_cmds;

	idx = -1;
	complete_cmds = get_cmds(all, argv, idx);
	if (!complete_cmds)
		return (0);
	get_to_bed(all, complete_cmds, envp);
	free_complete_cmds(all, complete_cmds);
	return (1);
}
