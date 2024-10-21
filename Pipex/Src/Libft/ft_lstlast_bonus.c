/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:16:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/05/30 14:01:02 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *ft_lst)
{
	t_list	*lst;

	if (!ft_lst)
		return (NULL);
	lst = ft_lst;
	while (lst->next)
		lst = lst->next;
	return (lst);
}
