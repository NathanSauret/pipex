/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:06:28 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/18 17:51:23 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_complete_cmds(char ***complete_cmds)
{
	int	i;

	i = 0;
	while (complete_cmds[i])
	{
		ft_printf("%s\n", complete_cmds[i][0]);
		ft_freetabstr(complete_cmds[i++]);
	}
}

static char	***get_cmds(t_all *all, char **argv, int idx)
{
	char	***complete_cmds;
	int		i;

	complete_cmds = malloc(sizeof(char **) * all->cmd_nb);
	if (!complete_cmds)
		return (NULL);
	i = 0;
	while (i < all->cmd_nb)
		complete_cmds[i++] = ft_split(argv[2 + all->here_doc + idx++], ' ');
	return (complete_cmds);
}

static void	get_to_bed(t_all *all, char ***complete_cmds)
{
	int	max_sleep;
	int	i;

	max_sleep = 0;
	i = 0;
	while (complete_cmds[i])
	{
		if (!ft_strncmp(complete_cmds[i][0], "sleep", 5)
			&& ft_atoi(complete_cmds[i][1]) > max_sleep)
		
	}
}

int	sleep_case(t_all *all, char **argv)
{
	int		idx;
	char	***complete_cmds;

	idx = all->idx;
	complete_cmds = get_cmds(all, argv, idx);
	if (!complete_cmds)
		return (0);
	free_complete_cmds(complete_cmds);
	return (1);
}
