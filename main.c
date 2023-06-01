/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:32:06 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/01 16:39:38 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void    leakssss(void)
{
    system("leaks push_swap");    
} */
 //atexit(leakssss);

int main(int argc, char **argv)
{
    char ***data_list;
    t_node *stack_a;
    t_node *stack_b;
    t_node *temp;
    
    stack_b = NULL;
    data_list = orgnize_input(argc, argv);
    check_data(data_list);
    stack_a = input_to_stack(data_list);
    check_repeat(stack_a);
    temp = stack_a;
    while (temp)
    {
        ft_printf("%d\n", temp->data);
        temp = temp->next;
    }
    push(&stack_a, &stack_b, 'b');
    push(&stack_a, &stack_b, 'b');
    push(&stack_a, &stack_b, 'b');
    reverse_rotate(&stack_a, 'a');
    double_swap(&stack_a, &stack_b);
    double_rotate(&stack_a, &stack_b);
    double_reverse_rotate(&stack_a, &stack_b);
    while (stack_a)
    {
        ft_printf("stack a: %d\n", stack_a->data);
        stack_a = stack_a->next;
    }
    while (stack_b)
    {
        ft_printf("stack b: %d\n", stack_b->data);
        stack_b = stack_b->next;
    }
    return(0);
    
}

