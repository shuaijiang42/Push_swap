/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:19:55 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/01 15:33:52 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function `ft_lstdelone` deletes a single node from a linked list and frees its memory.
 * 
 * @param lst lst is a pointer to a node in a linked list of type t_list. This node will be deleted by
 * the function.
 * @param del del is a function pointer that takes a void pointer as its parameter and returns nothing.
 * It is used to delete the content of the given node in the linked list.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		if (del && lst -> content)
			del((t_list *)lst -> content);
		free (lst);
		lst = NULL;
	}
}
