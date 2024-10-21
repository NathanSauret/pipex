/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:05:43 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/04 15:38:11 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd, int status);
char	*free_and_line(char *buffer, char **stache, int sz, int status);
char	*_get_line(char *stache);
char	*new_line(char *stache);

void	*ft_calloc(size_t ft_nmemb, size_t ft_size);
int		ft_strlen(const char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);

#endif
