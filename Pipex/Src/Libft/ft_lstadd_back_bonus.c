/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:23:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/07/31 14:23:19 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	return (1);
}
