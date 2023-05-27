/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:52 by gparpine          #+#    #+#             */
/*   Updated: 2023/04/24 15:16:27 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
 * The strdup() function allocates sufficient memory for a copy of the
 * string s, does the copy, and returns a pointer to it.  The pointer may
 * subsequently be used as an argument to the function free(3).
 * If insufficient memory is available, NULL is returned.
 */
char	*ft_strdup(const char *s)
{
	char	*result;

	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	return (ft_memcpy(result, s, ft_strlen(s)));
}
