/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:28:17 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 15:00:04 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	parse_fmt(char fmt, va_list args)
{
	int	w_bytes;

	w_bytes = 0;
	if (fmt == '%')
		w_bytes += print_char(fmt);
    else if (fmt == 'c')
		w_bytes += print_char(va_arg(args, int));
    /*
    else if (fmt == 's')
		w_bytes += print_str(va_arg(args, char *));
    else if (fmt == 'p')
		w_bytes += print_ptr(va_arg(args, void *));
    else if (fmt == 'd' || fmt == 'i')
		w_bytes += print_nbr(va_arg(args, int));
    else if (fmt == 'x' || fmt == 'X')
		w_bytes += print_hex(va_arg(args, unsigned int), fmt);
    else if (fmt == 'u')
		w_bytes += print_unbr(va_arg(args, unsigned int));
    */
	return (w_bytes);
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
        {
            i++;
            w_bytes += parse_fmt(fmt[i], args);
        }
		else
			w_bytes += print_char(fmt[i]);
		i++;
	}
	va_end(args);
	return (w_bytes);
}
