/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:00:45 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/14 16:19:35 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft.h"

int	ft_print_int(int el);
int	ft_print_char(int el);
int	ft_print_str(const char *el);
int	ft_print_pointer(unsigned long el);
int	ft_printf(const char *text, ...);
int	ft_print_unsigned(unsigned int el);
int	ft_print_hex(char type_of_hex, unsigned int el);

#endif
