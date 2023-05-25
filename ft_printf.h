/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:39:18 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/25 18:30:52 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	parse_fmt(char fmt, va_list args);
int	print_char(const char c);
int	print_str(const char *s);
int	print_nbr(int nb);
int	print_unbr(unsigned int nb);
int	print_hex(unsigned long n, int fmt);

#endif
