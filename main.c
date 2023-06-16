/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:32:06 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/16 18:57:28 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void    leakssss(void)
{
    system("leaks push_swap");    
} */
 //atexit(leakssss);
 
void printstack(t_node *node)
{
    while (node)
    {
        ft_printf("data: %d pos %d\n", node->data,node->pos);
        node = node->next;
    }
}

int main(int argc, char **argv)
{
    char ***data_list;
    t_node *stack_a;
    t_node *stack_b;

    stack_b = NULL;
    data_list = orgnize_input(argc, argv);
    check_data(data_list);
    stack_a = input_to_stack(data_list);
    check_repeat(stack_a);
    find_position(&stack_a);
    if (stack_size(stack_a) == 3)
        sort_three(&stack_a);
    else if (stack_size(stack_a) == 5)
        sort_five(&stack_a, &stack_b);
    else if (stack_size(stack_a) == 100)
    {
        chunk_a_to_b(&stack_a, &stack_b, 6);
        chunk_b_to_a(&stack_a, &stack_b, 99);
    }
    else if (stack_size(stack_a) == 500)
    {
        chunk_a_to_b(&stack_a, &stack_b, 15);
        chunk_b_to_a(&stack_a, &stack_b, 499);
    }
    return(0);  
}

