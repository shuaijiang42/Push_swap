/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_or_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:00:20 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/21 21:47:29 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int c;

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
	t_range *range;
	t_target *target;
	int counter; 
	
	counter = 0;
	range = iniciate_range(*stack_a, 0, -1);
	while (counter <2)
	{
		target = get_target(stack_a, range);
		go_top(target, stack_a, 'a');
		push(stack_a, stack_b, 'b');
		counter++;
	}
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
	if((*stack_a)->pos > (*stack_a)->next->pos)
		swap(stack_a, 'a');
}

void    sort_three_or_five(t_node **stack_a, t_node **stack_b)
{
    if (stack_size(*stack_a) == 3)
        sort_three(stack_a);
    else if (stack_size(*stack_a) == 5)
        sort_five(stack_a, stack_b);
}