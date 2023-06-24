/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:51:33 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/24 10:38:54 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creat a new node
t_node	*ft_new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

//go to the bottom of the stack
t_node	*ft_lst_node(t_node *stack)
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
void	ft_node_add_back(t_node **stack, t_node *new)
{
	t_node	*node;

	if (stack && *stack)
	{
		node = *stack;
		node = ft_lst_node(node);
		node->next = new;
		new->prev = node;
	}
	else
		*stack = new;
}

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size += 1;
	}
	return (size);
}
