/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:27:15 by nsauret           #+#    #+#             */
/*   Updated: 2024/05/30 14:03:53 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ft_s, int c, size_t ft_n)
{
	unsigned char	*s;
	int				i;
	int				n;

	s = ft_s;
	n = ft_n;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
