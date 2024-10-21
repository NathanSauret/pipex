/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:18:47 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/03 17:55:16 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc, char *argv[], t_all *all)
{
	int	i;

	if (argc < 5)
		return (0);
	if (argv[1] && !ft_strncmp("here_doc", argv[1], 9))
		all->here_doc = 1;
	else
		all->here_doc = 0;
	i = all->here_doc + 1;
	while (i < argc - 2)
	{
		if (argv[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}
