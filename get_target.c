/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:05:49 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/22 14:45:31 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_range *iniciate_range(t_node *stack, int chunk_size, int k)
{
	t_range *range;
	
	range = (t_range *)malloc(3 * sizeof(int));
	if (k == -1)
	{	
		range->max = 2;
		range->half = 0;
		range->min = 0;
	}	
	else if (k != 1)
	{
		range->min = k * chunk_size;
		range->half = (k + 1) * chunk_size;
		range->max = (k + 2) * chunk_size;
	}
	else
	{	
		range->max = stack_size(stack);
		range->half = 0;
		range->min = stack_size(stack) - 2;
	}
	return (range);
}

t_target	*count_steps(t_node **stack, t_range *range)
{
	t_target	*target;
	t_node	*temp;
	int		counter;
	
	counter = 0;
	temp = *stack;
	target = malloc(2*sizeof(int)+sizeof(t_node));
	while (temp)
	{
		if (temp->pos >= range->min && temp->pos < range->max)
			break ;
		temp = temp->next;
		counter++;
	}
	target->steps = counter;
	target->node = temp;
	target->dir = 0;
	return (target);
}

t_target	*count_steps_back(t_node **stack, t_range *range)
{
	t_target	*target;
	t_node	*temp;
	int		counter;
	
	counter = 1;
	temp = ft_lstNode(*stack);
	target = malloc(2*sizeof(int)+sizeof(t_node));
	while (temp)
	{
		if (temp->pos >= range->min && temp->pos < range->max)
			break ;
		temp = temp->prev;
		counter++;
	}
	target->steps = counter;
	target->node = temp;
	target->dir = 1;
	return (target);
}

t_target	*get_target(t_node **stack, t_range *range)
{
	t_target *target_top;
	t_target *target_bottom;

	target_top = count_steps(stack, range);
	target_bottom = count_steps_back(stack, range);
	if (target_top->steps <= target_bottom->steps)
		return(target_top);
	else
		return(target_bottom);
}
