/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:56:59 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/09 13:45:54 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static void	free_paths(char **paths)
{
	ft_freetabstr(paths);
	free(paths);
}

static char	*get_path_from_envp(char *envp[], char **args, int *pid)
{
	char	**paths;
	char	*path;
	int		i;

	path = NULL;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(ft_strjoin(paths[i], "/"), args[0]);
		if (!paths[i])
			return (free_paths(paths), NULL);
		if (access(paths[i], 0) == 0)
		{
			path = ft_strdup(paths[i]);
			return (free_paths(paths), path);
		}
		i++;
	}
	return (free_paths(paths), exit_error(2, path, args, pid), NULL);
}

char	*get_path(char *envp[], char **args, int *pid)
{
	char	*path;
	int		i;

	path = NULL;
	if (!char_in_str('/', args[0]))
	{
		i = 0;
		while (envp[i] && ft_strncmp("PATH", envp[i], 4))
			i++;
		if (envp[i] == NULL)
			exit_error(2, NULL, args, pid);
		path = get_path_from_envp(envp, args, pid);
	}
	else
	{
		if (access(args[0], 0) == 0)
			path = args[0];
		else
			exit_error(2, NULL, args, pid);
	}
	return (path);
}
