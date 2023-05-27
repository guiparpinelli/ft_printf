/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:52 by gparpine          #+#    #+#             */
/*   Updated: 2023/04/18 11:55:12 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The isprint() function tests for any printing character, including space.
 * The value of the argument must be representable as an unsigned char or
 * the value of EOF.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
