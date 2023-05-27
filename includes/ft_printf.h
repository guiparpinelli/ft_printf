/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:39:18 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 09:42:16 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	print_char(const char c);
int	print_str(const char *s);
int	print_ptr(void *ptr);
int	print_nbr(int nbr);
int	print_unbr(unsigned int nbr);
int	print_hex(unsigned int nbr, char fmt);

#endif
