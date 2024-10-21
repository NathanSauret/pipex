/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:05:40 by nsauret           #+#    #+#             */
/*   Updated: 2024/05/30 14:05:18 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_in_set(s1[end - 1], set))
		end--;
	trim = malloc(sizeof(char) * (end - start + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[start], (end - start + 1));
	return (trim);
}
