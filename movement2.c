/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:57:40 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/24 10:38:28 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//: Shift up all elements of a stack by 1. 
//The first element becomes the last one.

void	rotate_no_print(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	temp = NULL;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lst_node(*stack);
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}

void	rotate(t_node **stack, char c)
{
	rotate_no_print(stack);
	ft_printf("r%c\n", c);
}

//shift two stacks at the same time.
void	double_rotate(t_node **stack_a, t_node **stack_b)
{
	rotate_no_print(stack_a);
	rotate_no_print(stack_b);
	ft_printf("rr\n");
}
