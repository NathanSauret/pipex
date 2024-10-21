/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:31:11 by nsauret           #+#    #+#             */
/*   Updated: 2024/07/31 11:48:13 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ft_nmemb, size_t ft_size)
{
	void	*ptr;
	size_t	total_size;

	if (ft_nmemb == 0 || ft_size == 0)
		return (malloc(0));
	total_size = ft_nmemb * ft_size;
	if (total_size / ft_size != ft_nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
