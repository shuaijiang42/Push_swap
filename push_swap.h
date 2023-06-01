/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:35:06 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/01 16:15:31 by shujiang         ###   ########.fr       */
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
	struct s_node	*next;
}	t_node;

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
#endif