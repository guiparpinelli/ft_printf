/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:08:39 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/03 10:52:53 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Concatenates two strings 's1' and 's2' into a new string.
 * The new string is created with `ft_calloc` function, and the total length of
 * 's1' and 's2' plus one for the terminating null character.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcat(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result + ft_strlen(s1), s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (result);
}
