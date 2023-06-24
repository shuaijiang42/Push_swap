/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:22:59 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/24 10:38:03 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of a stack.
void	swap(t_node **stack, char c)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
	ft_printf("s%c\n", c);
}

//sa and sb at the same time.
/* void	double_swap(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
	ft_printf("ss\n");
} */

//Take the first element at the top of stack1 and put it at the top of stack2.
void	push(t_node **stack1, t_node **stack2, char c)
{
	t_node	*temp;

	temp = *stack1;
	if (!stack1 || !*stack1)
		return ;
	if (temp->next)
		temp->next->prev = NULL;
	*stack1 = temp->next;
	temp->next = *stack2;
	temp->prev = NULL;
	if (*stack2)
		(*stack2)->prev = temp;
	*stack2 = temp;
	ft_printf("p%c\n", c);
}

//Shift down all elements of a stack by 1.
//The last element becomes the first one.
/* void    reverse_rotate(t_node **stack, char c)
{
	t_node  *last;
	t_node  *penultimate;

	last = NULL;
	penultimate = NULL;
	if (!stack || !*stack)
		return ;
	last = ft_lstNode(*stack);
	penultimate = *stack;
	while(penultimate->next->next)
		penultimate = penultimate->next;
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rr%c\n", c);
	
} */

void	reverse_rotate(t_node **stack, char c)
{
	t_node	*last;
	t_node	*penultimate;

	last = NULL;
	penultimate = NULL;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lst_node(*stack);
	penultimate = last->prev;
	penultimate->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	ft_printf("rr%c\n", c);
}
