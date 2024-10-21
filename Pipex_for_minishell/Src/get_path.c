/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:56:59 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/04 15:18:43 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!*envp)
		return (NULL);
	return (*envp + 5);
}
