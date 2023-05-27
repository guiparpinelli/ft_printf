/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:11:23 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/03 11:14:04 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Adds the node 'new' at the beginning of the list 'lst'.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*element;

	element = new;
	element->next = *lst;
	*lst = element;
}
