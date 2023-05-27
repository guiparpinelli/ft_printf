/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:28:17 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 19:17:33 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	parse_fmt(char fmt, va_list args)
{
	if (fmt == '%')
		return (write(STDOUT_FILENO, &fmt, 1));
	else if (fmt == 'c')
	{
		ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
		return (1);
	}
	else if (fmt == 's')
		return (print_str(va_arg(args, char *)));
	else if (fmt == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (fmt == 'x' || fmt == 'X')
		return (print_hex(va_arg(args, unsigned int), fmt));
	else if (fmt == 'u')
		return (print_unbr(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		w_bytes;

	if (!fmt)
		return (0);
	i = 0;
	w_bytes = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			w_bytes += parse_fmt(fmt[++i], args);
		else
			w_bytes += write(STDOUT_FILENO, &fmt[i], 1);
		i++;
	}
	va_end(args);
	return (w_bytes);
}
