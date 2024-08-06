/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:12:48 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/06 17:19:49 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	long long		res;
	int				sign;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = 10 * res + (*nptr++ - '0');
		if ((sign == 1 && res > 2147483647))
			return (0);
		if ((sign == -1 && res - 1 > 2147483647))
			return (0);
	}
	return (res * sign);
}
