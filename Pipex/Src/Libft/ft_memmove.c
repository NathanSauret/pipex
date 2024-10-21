/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:25:55 by nsauret           #+#    #+#             */
/*   Updated: 2024/05/30 14:03:49 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *ft_dest, void *ft_src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	int				i;

	dest = ft_dest;
	src = ft_src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest && dest < src + n)
	{
		src += n;
		dest += n;
		while (n-- > 0)
			*--dest = *--src;
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
