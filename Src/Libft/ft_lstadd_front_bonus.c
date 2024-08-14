/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:52 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/14 16:01:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
	return (1);
}
