/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:31:28 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/16 14:39:05 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node **stack)
{
	int i;
	t_node *temp;
	
	i = 0;
	temp = *stack;
	if (!stack || !*stack)
		return ;
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next; 
	}
}

void    find_position(t_node **stack)
{  
	t_node *reference;
	t_node *copy;
	int	i; 
	
	reference = *stack;
	copy = *stack;
	while (copy)
	{
		i = 0;	
		while (reference)
		{
			if (copy->data > reference->data)
				i++;
			reference = reference->next;
			copy->pos = i;
		}
		reference = *stack;
		copy = copy->next;
	}
}

int	stack_size(t_node *stack)
{
	int	size;
	
	size = 0;
	while(stack)
	{
		stack = stack->next;
		size += 1;
	}
	return (size);
}

void	move_to_top(t_node **stack, t_node *node, char c)
{
	int	size;
	
	size = stack_size(*stack);
	assign_index(stack);
	if (*stack == node)
		return ;
	while (*stack && *stack != node && node)
	{
		if (node->index <= size/2)
			rotate(stack, c);
		else
			reverse_rotate(stack, c);
	}
}

void	chunk_a_to_b(t_node **stack_a, t_node **stack_b, int n_chunks)
{
	t_node *temp;
	int chunk_size;
	int k;
	chunk_size = stack_size(*stack_a)/n_chunks;
	k = 0;
	
	while ((*stack_a))
	{
		temp = *stack_a;
		while (temp)
		{
			if (temp->pos >= (k * chunk_size) && temp->pos < ((k + 2) * chunk_size))
			{
				move_to_top(stack_a, temp, 'a');
				push(stack_a, stack_b, 'b');
				if (temp && temp->pos < (k + 1) * chunk_size)
				{
					if ((*stack_a) && (*stack_a)->pos >= (k + 2) * chunk_size &&
						temp->next && temp->next->pos >= (k + 1) * chunk_size)	
						double_rotate(stack_a, stack_b);
					else
						rotate(stack_b, 'b');
				}
				temp = *stack_a;
			}
			else
				temp = temp->next;
		}
		k += 2;
	}
}

t_node	*get_max(t_node *stack, int n)
{
	while (stack)
	{
		if (stack->pos == n)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	chunk_b_to_a(t_node **stack_a, t_node **stack_b, int max_pos)
{
	t_node *max;
	
	max = NULL;
	while (*stack_b)
	{
		max = get_max(*stack_b, max_pos);
		move_to_top(stack_b, max, 'b');
		push(stack_b, stack_a, 'a');
		max_pos -= 1;
		chunk_b_to_a(stack_a, stack_b, max_pos);
	}
}
