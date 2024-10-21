/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:31:46 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/18 17:47:22 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *nptr);
void	ft_freetabstr(char **tab);
char	*ft_itoa(int ft_n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_uitoa(unsigned int ft_n);

#endif