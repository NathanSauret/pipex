/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:44:40 by nathan            #+#    #+#             */
/*   Updated: 2024/07/26 15:04:59 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **lst)
{
	if (!*lst)
		return ;
	if ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		free((*lst)->prev);
		(*lst)->prev = NULL;
	}
	else
	{
		free(*lst);
		*lst = NULL;
	}
}
