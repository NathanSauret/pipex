/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:20:00 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/04 15:49:07 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
