/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:28:17 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/25 19:21:00 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	parse_fmt(char fmt, va_list args)
{
	int	w_bytes;

	w_bytes = 0;
	if (fmt == '%')
		w_bytes += print_char(fmt);
	if (fmt == 'c')
		w_bytes += print_char(va_arg(args, int));
	if (fmt == 's')
		w_bytes += print_str(va_arg(args, char *));
	if (fmt == 'p')
	{
		w_bytes += print_str("0x");
		w_bytes += print_hex(va_arg(args, unsigned long), 'x');
	}
	if (fmt == 'd' || fmt == 'i')
		w_bytes += print_nbr(va_arg(args, int));
	if (fmt == 'x' || fmt == 'X')
		w_bytes += print_hex(va_arg(args, unsigned int), fmt);
	if (fmt == 'u')
		w_bytes += print_unbr(va_arg(args, unsigned int));
	return (w_bytes);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		w_bytes;

	i = 0;
	w_bytes = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			w_bytes += parse_fmt(fmt[++i], args);
		else
			w_bytes += print_char(fmt[i]);
		i++;
	}
	va_end(args);
	return (w_bytes);
}
