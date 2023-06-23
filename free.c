/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:55:19 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/23 19:28:51 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void    free_stack(t_node **stack)
{
	while((*stack)->next)
	{
		*stack = (*stack)->next;
		//free((*stack)->prev);
	}
	free((*stack));
} */

void	free_stack(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = *stack;
	while (temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	}
}

void	free_input_list(char ***input_list)
{
	int	i;
	int	j;

	i = 0;
	while (input_list[i])
	{
		j = 0;
		while (input_list[i][j])
		{
			free(input_list[i][j]);
			j++;
		}
		free(input_list[i]);
		i++;
	}
	free(input_list);
}
