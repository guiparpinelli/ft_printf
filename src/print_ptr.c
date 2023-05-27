/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:15:34 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 19:15:35 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ptrlen(unsigned long long nbr)
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

static void	put_ptr(unsigned long long ptr)
{
	char	*base;

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
	return (ptrlen((unsigned long long)ptr) + 2);
}
