/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:14:32 by nsauret           #+#    #+#             */
/*   Updated: 2024/05/30 13:55:27 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		len;

	len = ft_strlen(s);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	dup[len] = '\0';
	return (dup);
}
