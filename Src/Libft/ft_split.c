/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:34:01 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/17 00:58:00 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_count++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (word_count);
}

static int	ft_free_list(char **list_ptr, char **list)
{
	while (list_ptr > list)
	{
		free(*(list_ptr - 1));
		list_ptr--;
	}
	free(list);
	return (0);
}

static int	ft_split_helper(char **list_ptr, char **list, char const *s, char c)
{
	char	*seg;
	char	*seg_ptr;
	int		len_seg;

	while (*s)
	{
		if (*s != c)
		{
			len_seg = 0;
			while (s[len_seg] && s[len_seg] != c)
				len_seg++;
			seg = malloc(sizeof(char) * (len_seg + 1));
			if (!seg)
				return (ft_free_list(list_ptr, list));
			seg_ptr = seg;
			while (*s != c && *s)
				*seg_ptr++ = *s++;
			*seg_ptr = '\0';
			*list_ptr++ = seg;
		}
		if (*s)
			s++;
	}
	*list_ptr = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	char	**list_ptr;
	int		help_int;

	if (!s)
		return (NULL);
	list = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!list)
		return (NULL);
	list_ptr = list;
	help_int = ft_split_helper(list_ptr, list, s, c);
	if (help_int == 0)
		return (NULL);
	return (list);
}
