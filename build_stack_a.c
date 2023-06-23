/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:54:27 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/23 19:23:38 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Split argv by spc
char	***creat_input_list(char **argv, char ***input_list)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] == ' ')
			j++;
		if (j == (int)ft_strlen(argv[i]))
			exit(0);
		input_list[i - 1] = ft_split(argv[i], ' ');
		i++;
		j = 0;
	}
	input_list[i - 1] = NULL;
	return (input_list);
}

char	***orgnize_input(int argc, char **argv)
{
	char	***input_list;

	if (!argv)
		return (NULL);
	input_list = (char ***)malloc(argc * sizeof(char **));
	if (!input_list)
		return (NULL);
	if (!argv[1])
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	input_list = creat_input_list(argv, input_list);
	return (input_list);
}

t_node	*input_to_stack(char ***data_list)
{
	t_node	*stack;
	t_node	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	stack = NULL;
	while (data_list[i])
	{
		while (data_list[i][j])
		{
			new = ft_newNode(ft_atoi(data_list[i][j]));
			ft_nodeAdd_back(&stack, new);
			j++;
		}
		i++;
		j = 0;
	}
	free_input_list(data_list);
	return (stack);
}

void	find_position(t_node **stack)
{
	t_node	*reference;
	t_node	*copy;
	int		i;

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

t_node	*build_stack_a(int argc, char **argv)
{
	t_node	*stack;
	char	***data_list;

	data_list = orgnize_input(argc, argv);
	check_data(data_list);
	stack = input_to_stack(data_list);
	check_repeat(stack);
	find_position(&stack);
	return (stack);
}
