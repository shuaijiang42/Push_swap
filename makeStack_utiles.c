/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeStack_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:51:33 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/01 12:52:48 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creat a new node
t_node	*ft_newNode(int data)
{
	t_node *node;
	
	node = malloc(sizeof(t_node));
	if (!node)
		return(NULL);
	node->data = data;
	node->next = NULL;
	return(node);
}

//go to the bottom of the stack
t_node	*ft_lstNode(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	return (stack);
}
//add data to the bottom of the stack
void	ft_nodeAdd_back(t_node **stack, t_node *new)
{
	t_node	*node;
	
	if(stack && *stack)
	{
		node = *stack;
		node = ft_lstNode(node);
		node->next = new;
	}
	else
		*stack = new; 
}
