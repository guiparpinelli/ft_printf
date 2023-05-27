/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:52 by gparpine          #+#    #+#             */
/*   Updated: 2023/04/18 19:43:12 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * strlcat() take the full size of the destination buffer and guarantee
 * NUL-termination if there is room.  Note that room for the NUL should be
 * included in size. Also note that strlcat() only operate on true ''C''
 * strings. This means that both src and dst() must be NUL-terminated.
 *
 * strlcat() appends string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 characters.
 * It will then NUL-terminate, unless size is 0 or the original dst string
 * was longer than size (in practice this should not happen as it means that
 * either size is incorrect or that dst is not a proper string).
 *
 * If the src and dst strings overlap, the behavior is undefined.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (size == 0)
		return (src_len);
	if (size < dst_len)
		return (src_len + size);
	else
	{
		while (src[j] && (dst_len + j) < size)
			dst[i++] = src[j++];
		if ((dst_len + j) == size && dst_len < size)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (src_len + dst_len);
	}
}
