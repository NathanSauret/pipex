/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:43:46 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/14 16:08:19 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_int_len(int el)
{
	int	len;

	if (el == 0)
		return (1);
	if (el == -2147483648)
		return (11);
	len = 0;
	if (el < 0)
	{
		el *= -1;
		len ++;
	}
	while (el > 0)
	{
		el /= 10;
		len++;
	}
	return (len);
}

int	ft_print_int(int el)
{
	char	*str_el;

	str_el = ft_itoa(el);
	ft_print_str(str_el);
	free(str_el);
	return (get_int_len(el));
}
