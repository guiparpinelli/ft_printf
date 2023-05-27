/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:15:50 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/03 11:13:13 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns a pointer to the last node of the list 'lst'.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*n;

	n = lst;
	if (n == NULL)
		return (NULL);
	if (n->next == NULL)
		return (n);
	while (n != NULL)
	{
		if (n->next == NULL)
			return (n);
		n = n->next;
	}
	return (NULL);
}
