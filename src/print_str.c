/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:15:38 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/27 19:15:38 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_str(const char *s)
{
	if (s == NULL)
		return (print_str("(null)"));
	else
		return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
