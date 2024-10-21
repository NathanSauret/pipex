/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:04:12 by nsauret           #+#    #+#             */
/*   Updated: 2024/05/30 14:03:28 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *ft_lst)
{
	int		len;
	t_list	*lst;

	if (!ft_lst)
		return (0);
	lst = ft_lst;
	len = 1;
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
