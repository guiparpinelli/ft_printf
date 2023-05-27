/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:15:24 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 19:15:32 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static size_t	nbrlen(int nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
		len++;
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
		return (write(STDOUT_FILENO, "0", 1));
	if (nbr == INT_MIN)
		return (print_str("-2147483648"));
	ft_putnbr_fd(nbr, STDOUT_FILENO);
	return (nbrlen(nbr));
}
