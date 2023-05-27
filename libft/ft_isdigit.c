/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:52 by gparpine          #+#    #+#             */
/*   Updated: 2023/04/18 11:54:05 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The isdigit() function tests for a decimal digit character (0-9).
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
