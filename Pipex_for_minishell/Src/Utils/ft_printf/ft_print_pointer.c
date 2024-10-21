/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:15:21 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/04 15:49:22 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_hex_len(unsigned long el)
{
	int	len;

	len = 2;
	while (el > 0)
	{
		el /= 16;
		len++;
	}
	return (len);
}

int	ft_print_pointer(unsigned long el)
{
	int				len;
	int				i;
	char			*hex;
	char			*hex_value;

	if (!el)
		return (ft_print_str("(nil)"), 5);
	hex = "0123456789abcdef";
	len = get_hex_len(el);
	hex_value = malloc(sizeof(void) * len + 1);
	if (!hex_value)
		return (0);
	i = len - 1;
	while (i >= 0)
	{
		hex_value[i] = hex[el % 16];
		el /= 16;
		i--;
	}
	hex_value[0] = '0';
	hex_value[1] = 'x';
	hex_value[len] = '\0';
	ft_print_str(hex_value);
	free(hex_value);
	return (len);
}
