/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:21:14 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/03 11:08:15 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Applies the function 'f' to each character of the string 's' along with its
 * index.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
