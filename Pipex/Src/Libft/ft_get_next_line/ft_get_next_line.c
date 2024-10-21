/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:05:47 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/15 00:05:58 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, int status)
{
	char		*buffer;
	static char	*stache;
	int			sz;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	sz = BUFFER_SIZE;
	while (sz > 0)
	{
		sz = read(fd, buffer, BUFFER_SIZE);
		if ((sz == 0 && stache && stache[0] == 0) || sz == -1)
			break ;
		buffer[sz] = '\0';
		if (!stache)
			stache = ft_strdup(buffer);
		else
			stache = gnl_strjoin(stache, buffer);
		if (!stache || ft_strchr(stache, '\n'))
			break ;
	}
	return (free_and_line(buffer, &stache, sz, status));
}

char	*free_and_line(char *buffer, char **stache, int sz, int status)
{
	char	*line;

	free(buffer);
	if (!*stache)
		return (NULL);
	if (status == 0 || (sz == 0 && (*stache)[0] == 0) || sz == -1)
	{
		free(*stache);
		*stache = NULL;
		return (NULL);
	}
	line = _get_line(*stache);
	*stache = new_line(*stache);
	return (line);
}

char	*_get_line(char *stache)
{
	int		i;
	int		len;
	char	*line;

	if (!stache)
		return (NULL);
	len = 0;
	while (stache[len] && (len == 0 || stache[len - 1] != '\n'))
		len++;
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stache[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_line(char *stache)
{
	char	*new_stache;
	int		i;
	int		j;

	if (!stache)
		return (NULL);
	i = 0;
	while (stache[i] && stache[i] != '\n')
		i++;
	if (stache[i] == '\n')
		i++;
	new_stache = ft_calloc(ft_strlen(stache + i) + 1, sizeof(char));
	if (!new_stache)
		return (NULL);
	j = 0;
	while (stache[i] != '\0')
	{
		new_stache[j] = stache[i];
		i++;
		j++;
	}
	new_stache[j] = '\0';
	free(stache);
	return (new_stache);
}
