/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:20:00 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/14 16:08:15 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_str(const char *el)
{
	int	len;

	if (!el)
	{
		ft_print_str("(null)");
		return (6);
	}
	if (*el == '\0')
		return (0);
	len = 0;
	while (*el)
	{
		ft_print_char(*el++);
		len++;
	}
	return (len);
}
