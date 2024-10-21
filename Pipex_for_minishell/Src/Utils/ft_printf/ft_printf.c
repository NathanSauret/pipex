/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:57:50 by nsauret           #+#    #+#             */
/*   Updated: 2024/10/04 15:48:20 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_choose_print(const char *text, va_list ptr)
{
	int	func_res_len;

	if (*text == 'c')
		func_res_len = ft_print_char(va_arg(ptr, int));
	else if (*text == 's')
		func_res_len = ft_print_str(va_arg(ptr, char *));
	else if (*text == 'p')
		func_res_len = ft_print_pointer(va_arg(ptr, unsigned long));
	else if (*text == 'd' || *text == 'i')
		func_res_len = ft_print_int(va_arg(ptr, int));
	else if (*text == 'u')
		func_res_len = ft_print_unsigned(va_arg(ptr, unsigned int));
	else if (*text == 'x' || *text == 'X')
		func_res_len = ft_print_hex(*text, va_arg(ptr, int));
	else if (*text == '%')
	{
		ft_print_char('%');
		func_res_len = 1;
	}
	else
		return (-1);
	return (func_res_len);
}

static void	error_return(const char *text)
{
	ft_print_char('%');
	ft_print_char(*text);
}

int	ft_printf(const char *text, ...)
{
	va_list	ptr;
	int		len;

	if (!text)
		return (-1);
	len = 0;
	va_start(ptr, text);
	while (*text)
	{
		if (*text == '%')
		{
			text++;
			len += ft_choose_print(text, ptr);
			if (len == -1)
				error_return(text);
		}
		else
		{
			ft_print_char(*text);
			len++;
		}
		text++;
	}
	va_end(ptr);
	return (len);
}
