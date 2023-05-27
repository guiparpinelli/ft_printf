/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:04:32 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 15:01:27 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int	print_char(char c)
{
    ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	print_str(const char *s)
{
	if (s == NULL)
		return (print_str("(null)"));
    else
        return (write(STDOUT_FILENO, s, ft_strlen(s)));
}

static size_t   nbrlen(int nbr)
{
    size_t  len;

    if (nbr == 0)
        return (1);
    len = 0;
    while (nbr != 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

int	print_nbr(int nbr)
{
	if (nbr == 0)
		return (print_char('0'));
	if (nbr == INT_MIN)
		return (print_str("-2147483648"));
    ft_putnbr_fd(nbr, STDOUT_FILENO);
	return (nbrlen(nbr));
}

int	print_unbr(unsigned int nbr)
{
	if (nbr > 9)
		print_unbr(nbr / 10);
    ft_putchar_fd("0123456789"[nbr % 10], STDOUT_FILENO);
	return (nbrlen(nbr));
}

static size_t   hexlen(unsigned int nbr)
{
    size_t  len;

    if (nbr == 0)
        return (1);
    len = 0;
    while (nbr != 0)
    {
        nbr /= 16;
        len++;
    }
    return (len);
}

int	print_hex(unsigned int nbr, char fmt)
{
	char	*base;

	if (nbr == 0)
		return (print_char('0'));
	if (fmt == 'x')
		base = "0123456789abcdef";
	else if (fmt == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		print_hex(nbr / 16, fmt);
	else
		ft_putchar_fd(base[nbr % 16], STDOUT_FILENO);
	return (hexlen(nbr));
}

static void put_ptr(unsigned long long ptr)
{
	static char	*base;

    base = "0123456789abcdef";
	if (ptr >= 16)
		put_ptr(ptr / 16);
    ft_putchar_fd(base[ptr % 16], STDOUT_FILENO);
}

int	print_ptr(void *ptr)
{

	if (ptr == NULL)
		return (print_str("(nil)"));
    print_str("0x");
    put_ptr((unsigned long long)ptr);
	return (hexlen((unsigned long long)ptr) + 2);
}
