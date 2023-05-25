/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:04:32 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/25 19:18:26 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

int	print_char(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(const char *s)
{
	int	len;

	if (!s)
		return (print_str("(null)"));
	len = 0;
	while (s[len] != '\0')
		len++;
	write(1, s, len);
	return (len);
}

int	print_nbr(int nb)
{
	int	w_bytes;

	w_bytes = 0;
	if (nb == 0)
		return (print_char('0'));
	if (nb == INT_MIN)
		return (print_str("-2147483648"));
	if (nb < 0)
	{
		w_bytes += print_char('-');
		nb *= -1;
	}
	if (nb < 10)
		w_bytes += print_char(nb + '0');
	else
	{
		w_bytes += print_nbr(nb / 10);
		w_bytes += print_char((nb % 10) + '0');
	}
	return (w_bytes);
}

int	print_unbr(unsigned int nb)
{
	int	w_bytes;

	w_bytes = 0;
	if (nb >= 10)
	{
		w_bytes += print_unbr(nb / 10);
		w_bytes += print_unbr(nb % 10);
	}
	else
		w_bytes += print_char("0123456789"[(int)nb]);
	return (w_bytes);
}

int	print_hex(unsigned long n, int fmt)
{
	int		w_bytes;
	char	*base;

	w_bytes = 0;
	if (n == 0)
		return (print_char('0'));
	if (fmt == 'x')
		base = "0123456789abcdef";
	else if (fmt == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		w_bytes += print_hex(n / 16, fmt);
		w_bytes += print_hex(n % 16, fmt);
	}
	else
		w_bytes += print_char(base[n]);
	return (w_bytes);
}
