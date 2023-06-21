/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:35:06 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/20 14:15:19 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int	data;
	int pos;
	int	index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_range
{
	int	max;
	int half;
	int	min;
}	t_range;

typedef struct s_target
{
	int	steps;
	int dir;
	struct s_node *node;
}	t_target;

//parsing
long	ft_atol_check_int_range(const char *str);
void	lenth_and_digit_check(const char *str);
char    ***orgnize_input(int argc, char **argv);
void	check_data(char ***data_list);
t_node	*input_to_stack(char ***data_list);
void	check_repeat(t_node *stack);

//stack building
t_node	*ft_newNode(int data);
t_node	*ft_lstNode(t_node *stack);
void	ft_nodeAdd_back(t_node **stack, t_node *new);

//movements
void    swap(t_node **stack, char c);
void    double_swap(t_node **stack_a, t_node **stack_b);
void    push(t_node **stack1, t_node **stack2, char c);
void    rotate(t_node **stack, char c);
void    double_rotate(t_node **stack_a, t_node **stack_b);
void    reverse_rotate(t_node **stack, char c);
void    double_reverse_rotate(t_node **stack_a, t_node **stack_b);

void    find_position(t_node **stack);
void	assign_index(t_node **stack);
int		stack_size(t_node *stack);
//void	chunk_a_to_b(t_node **stack_a, t_node **stack_b, int n_chunks);
//void	move_to_top(t_node **stack, t_node *node, char c);
//void	chunk_b_to_a(t_node **stack_a, t_node **stack_b, int max_pos);
void    sort_three_or_five(t_node **stack_a, t_node **stack_b);
void 	move_to_top(t_node **stack, t_range *range, char c);
void	chunk_a_to_b(t_node **stack_a, t_node **stack_b, int n_chunks);
void	chunk_b_to_a(t_node **stack_a, t_node **stack_b);
void 	printstack(t_node *node);
#endif