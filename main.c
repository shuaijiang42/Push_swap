/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:32:06 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/23 19:46:02 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void    leakssss(void)
{
	system("leaks push_swap");    
} */
//atexit(leakssss);

/* void printstack(t_node *node)
{
	while (node)
	{
		ft_printf("data: %d pos %d\n", node->data,node->pos);
		node = node->next;
	}
} */

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = build_stack_a(argc, argv);
	if (if_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}	
	if (stack_size(stack_a) <= 5 && stack_size(stack_a) > 0
		&& stack_size(stack_a) != 4)
		sort_until_five(&stack_a, &stack_b);
	else if (stack_size(stack_a) == 100)
		chunk_a_to_b(&stack_a, &stack_b, 6);
	else if (stack_size(stack_a) == 500)
		chunk_a_to_b(&stack_a, &stack_b, 14);
	else
		chunk_a_to_b(&stack_a, &stack_b, 2);
	chunk_b_to_a(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
