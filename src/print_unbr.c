/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:15:41 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 19:15:41 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	unbrlen(unsigned int nbr)
{
	size_t	len;

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

int	print_unbr(unsigned int nbr)
{
	char	*base;

	base = "0123456789";
	if (nbr > 9)
		print_unbr(nbr / 10);
	ft_putchar_fd(base[nbr % 10], STDOUT_FILENO);
	return (unbrlen(nbr));
}
