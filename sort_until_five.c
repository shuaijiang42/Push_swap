/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_until_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:00:20 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/23 20:10:09 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_sorted(t_node *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->data < stack_a->next->data)
		{
			stack_a = stack_a->next;
		}	
		else
			return (0);
	}
	return (1);
}

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->pos;
	b = (*stack)->next->pos;
	c = (*stack)->next->next->pos;
	if (a < b && b < c)
		return ;
	else if (a < c && b > c)
	{
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (a > b && a < c)
		swap(stack, 'a');
	else if (a > c && a < b)
		reverse_rotate(stack, 'a');
	else if (b < c && a > b)
		rotate(stack, 'a');
	else
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	t_range		*range;
	t_target	*target;
	int			counter;

	counter = 0;
	range = iniciate_range(*stack_a, 0, -1);
	while (counter < 2)
	{
		target = get_target(stack_a, range);
		go_top(target, stack_a, 'a');
		push(stack_a, stack_b, 'b');
		counter++;
		free(target);
	}
	free(range);
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
	if ((*stack_a)->pos > (*stack_a)->next->pos)
		swap(stack_a, 'a');
}

void	sort_until_five(t_node **stack_a, t_node **stack_b)
{
	if (stack_size(*stack_a) == 1)
	{
		free_stack(stack_a);
		exit(0);
	}
	if (stack_size(*stack_a) == 2)
		swap(stack_a, 'a');
	else if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else if (stack_size(*stack_a) == 5)
		sort_five(stack_a, stack_b);
}
