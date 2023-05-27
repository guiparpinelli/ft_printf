/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:52 by gparpine          #+#    #+#             */
/*   Updated: 2023/04/24 14:20:47 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The calloc() function allocates memory for an array of nmemb elements of 
 * size bytes each and returns a pointer to the allocated memory. The memory is
 * set to zero. If nmemb or size is 0, then calloc() returns either NULL, or a 
 * unique pointer value that can later be successfully passed to free(). If the 
 * multiplication of nmemb and size would result in integer overflow, then 
 * calloc() returns an error. By contrast, an integer overflow would not be 
 * detected in the following call to malloc(), with the result that an 
 * incorrectly sized block of memory would be allocated: `malloc(nmemb * size)`
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
