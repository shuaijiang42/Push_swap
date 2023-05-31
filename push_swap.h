/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:35:06 by shujiang          #+#    #+#             */
/*   Updated: 2023/05/31 15:33:59 by shujiang         ###   ########.fr       */
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

long	ft_atol_check_int_range(const char *str);
void	lenth_and_digit_check(const char *str);
char    ***orgnize_input(int argc, char **argv);
void check_data(char ***data_list);
t_node	*input_to_stack(char ***data_list);
void	check_repeat(t_node *stack);
#endif