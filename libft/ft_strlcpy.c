/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:52 by gparpine          #+#    #+#             */
/*   Updated: 2023/04/18 20:58:12 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * strlcpy() take the full size of the destination buffer and guarantee
 * NUL-termination if there is room.  Note that room for the NUL should
 * be included in size.  Also note that strlcpy() only operate on true
 * ''C'' strings. This means that src must be NUL-terminated.
 *
 * strlcpy() copies up to size - 1 characters from the string src to dst,
 * NUL-terminating the result if size is not 0.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = -1;
	if (size != 0)
	{
		while (src[++i] && i < (size - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (src_len);
}
