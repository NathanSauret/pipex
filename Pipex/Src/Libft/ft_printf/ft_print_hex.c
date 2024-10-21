/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:21:54 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/14 16:08:20 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_hex_len(unsigned int el)
{
	int	len;

	if (el == 0)
		return (1);
	len = 0;
	while (el > 0)
	{
		el /= 16;
		len++;
	}
	return (len);
}

static int	ft_print_hex_helper(char *hex_set, unsigned int el, int len)
{
	char	*res;
	int		i;

	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[len - 1 - i] = hex_set[el % 16];
		el /= 16;
		i++;
	}
	res[len] = '\0';
	i = 0;
	while (res[i] != '\0')
	{
		ft_print_char(res[i]);
		i++;
	}
	free(res);
	return (len);
}

int	ft_print_hex(char type_of_hex, unsigned int el)
{
	int		len;
	char	*hex_set;

	if (type_of_hex == 'x')
		hex_set = "0123456789abcdef";
	else
		hex_set = "0123456789ABCDEF";
	len = get_hex_len(el);
	return (ft_print_hex_helper(hex_set, el, len));
}
