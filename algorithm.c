/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:31:28 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/21 17:34:52 by shujiang         ###   ########.fr       */
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

/* void	move_to_top(t_node **stack, t_node *node, char c)
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
} */
/*
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
		if (stack->pos == n || stack->pos == n-1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	chunk_b_to_a(t_node **stack_a, t_node **stack_b, int max_pos)
{
	t_node *max;

	int counter;
	max = NULL;
	counter = 0;
	while (*stack_b)
	{
		max = get_max(*stack_b, max_pos);
		if (max)
		{
			move_to_top(stack_b, max, 'b');
			push(stack_b, stack_a, 'a');
			if ((*stack_a)->next && (*stack_a)->pos > (*stack_a)->next->pos)
				swap(stack_a, 'a');
			counter++;
		}
		if (counter == 2)
		{
			max_pos -= 2;
			counter = 0;
		}		
	}
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
} */

t_range *iniciate_range(t_node *stack, int chunk_size, int k)
{
	t_range *range;
	
	range = (t_range *)malloc(3 * sizeof(int));
	if (k != 1)
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

void	chunk_a_to_b(t_node **stack_a, t_node **stack_b, int n_chunks)
{
	int	chunk_size;
	t_target *target;
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
			target = get_target(stack_a, range);
			go_top(target, stack_a, 'a');
			push(stack_a, stack_b, 'b');
			counter++;
			if ((*stack_b)->pos < range->half && (*stack_b)->next && (*stack_b)->next->pos >= range->half)
			{
				target = get_target(stack_a, range);
				if (target &&!(target->dir) && (*stack_a) && (*stack_a)->pos >= range->max)
					double_rotate(stack_a, stack_b);
				else
					rotate(stack_b, 'b');
			}
		}
		k += 2;
	}
}

void	chunk_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_target *target;
	t_range *range;
	int counter;
	
	while (*stack_b)
	{	
		counter = 0;
		range = iniciate_range(*stack_b, 2, 1);
		while(counter < 2)
		{
			target = get_target(stack_b, range);
			go_top(target, stack_b, 'b');
			push(stack_b, stack_a, 'a');
			counter++;
			if (*stack_a && (*stack_a)->next && (*stack_a)->pos > (*stack_a)->next->pos)
				swap(stack_a, 'a');
		}	
	}
}

