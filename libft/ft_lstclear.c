/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:11:02 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/01 15:31:33 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function `ft_lstclear` clears a linked list by deleting each node and its content using a given
 * function pointer.
 * 
 * @param lst A pointer to a pointer to the first node of a linked list.
 * @param del The "del" parameter is a function pointer that points to a function responsible for
 * deleting the content of a node in the linked list. This function takes a void pointer as its
 * parameter, which represents the content of the node to be deleted. The purpose of this parameter is
 * to ensure that all memory allocated
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*successor;

	node = *lst;
	successor = NULL;
	while (node != NULL)
	{
		successor = node -> next;
		del(node->content);
		free(node);
		node = successor;
	}
	*lst = NULL;
}
