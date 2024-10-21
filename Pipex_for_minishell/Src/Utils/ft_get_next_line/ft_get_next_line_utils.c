/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:05:51 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/13 17:06:04 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t ft_nmemb, size_t ft_size)
{
	char	*ptr;
	size_t	total_size;
	size_t	i;

	if (ft_nmemb == 0 || ft_size == 0)
		return (malloc(0));
	total_size = ft_nmemb * ft_size;
	if (total_size / ft_size != ft_nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
		ptr[i++] = '\0';
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	join = malloc(sizeof(char) * len1 + len2 + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		join[i] = s2[i - len1];
		i++;
	}
	join[i] = '\0';
	return (free(s1), join);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < (len + 1) - 1 && s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
