/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:15:03 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 19:19:01 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static size_t	hexlen(unsigned int nbr)
{
	size_t	len;

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
	char	*lower_base;
	char	*upper_base;

	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	if (nbr == 0)
		return (write(STDOUT_FILENO, "0", 1));
	if (nbr >= 16)
		print_hex((nbr / 16), fmt);
	if (fmt == 'x')
		ft_putchar_fd(lower_base[nbr % 16], STDOUT_FILENO);
	else if (fmt == 'X')
		ft_putchar_fd(upper_base[nbr % 16], STDOUT_FILENO);
	return (hexlen(nbr));
}
