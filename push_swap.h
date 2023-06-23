/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:35:06 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/23 20:12:19 by shujiang         ###   ########.fr       */
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
	int				data;
	int				pos;
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
t_node	*build_stack_a(int argc, char **argv);
int		if_sorted(t_node *stack_a);
//stack building
t_node	*ft_new_node(int data);
t_node	*ft_lst_node(t_node *stack);
void	ft_node_add_back(t_node **stack, t_node *new);

//movements
void    swap(t_node **stack, char c);
void    push(t_node **stack1, t_node **stack2, char c);
void    rotate(t_node **stack, char c);
void    double_rotate(t_node **stack_a, t_node **stack_b);
void    reverse_rotate(t_node **stack, char c);

void    find_position(t_node **stack);
int		stack_size(t_node *stack);
void 	sort_until_five(t_node **stack_a, t_node **stack_b);

void	chunk_a_to_b(t_node **stack_a, t_node **stack_b, int n_chunks);
void	chunk_b_to_a(t_node **stack_a, t_node **stack_b);
void 	printstack(t_node *node);
t_range		*iniciate_range(t_node *stack, int chunk_size, int k);
t_target	*get_target(t_node **stack, t_range *range);
void	go_top (t_target *target, t_node **stack, char c);

void    free_stack(t_node **stack);
void	free_input_list(char ***input_list);
void	*ft_free_strings(char **strings);

#endif