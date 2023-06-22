/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:31:28 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/22 14:46:59 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_top (t_target *target, t_node **stack, char c)
{
	if(target->steps == 0)
	{
		if(target->dir == 0)
			return ;
		else
		{
			reverse_rotate(stack, c);
			return ;	
		}	
	}
	while (target->steps)
	{
		if (target->dir == 0)
			rotate (stack, c);
		else if (target->dir == 1)
			reverse_rotate(stack, c);
		target->steps--;
	}
}

void	push_target_b(t_node **stack_a, t_node **stack_b, t_range *range)
{
	t_target *target;

	target = get_target(stack_a, range);
	go_top(target, stack_a, 'a');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->pos < range->half && (*stack_b)->next && (*stack_b)->next->pos >= range->half)
	{
		target = get_target(stack_a, range);
		if (target &&!(target->dir) && (*stack_a) && (*stack_a)->pos >= range->max)
			double_rotate(stack_a, stack_b);
		else
			rotate(stack_b, 'b');
	}
}

void	push_target_a(t_node **stack_a, t_node **stack_b, t_range *range)
{
	t_target *target;

	target = get_target(stack_b, range);
	go_top(target, stack_b, 'b');
	push(stack_b, stack_a, 'a');
	if (*stack_a && (*stack_a)->next && (*stack_a)->pos > (*stack_a)->next->pos)
		swap(stack_a, 'a');
}

void	chunk_a_to_b(t_node **stack_a, t_node **stack_b, int n_chunks)
{
	int	chunk_size;
	t_range *range;
	int	k;
	int counter;
	
	k = 0;
	chunk_size = stack_size(*stack_a)/n_chunks;
	while (*stack_a)
	{
		counter = 0;
		range = iniciate_range(*stack_a, chunk_size, k);
		while (counter < 2 * chunk_size)
		{	
			push_target_b(stack_a, stack_b, range);
			counter++;
		}
		k += 2;
	}
}

void	chunk_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_range *range;
	int counter;
	
	while (*stack_b)
	{	
		counter = 0;
		range = iniciate_range(*stack_b, 2, 1);
		while(counter < 2)
		{
			push_target_a(stack_a, stack_b, range);
			counter++;
		}	
	}
}
