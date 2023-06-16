/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:22:59 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/16 12:42:05 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of a stack.
void    swap(t_node **stack, char c)
{
    t_node *temp;
    
    if(!stack || !*stack || !(*stack)->next)
        return ;
    temp = *stack;
    *stack = (*stack)->next;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
    ft_printf("s%c\n", c);
}
//sa and sb at the same time.
void    double_swap(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a, 'a');
    swap(stack_b, 'b');
    ft_printf("ss\n");
}

//Take the first element at the top of stack1 and put it at the top of stack2.
void    push(t_node **stack1, t_node **stack2, char c)
{
    t_node *temp;
    
    temp = NULL;
    if(!stack1 || !*stack1)
        return ;
    temp = (*stack1)->next;
    (*stack1)->next = *stack2;
    *stack2 = *stack1; 
    *stack1 = temp;
    ft_printf("p%c\n", c);
}

//: Shift up all elements of a stack by 1. 
//The first element becomes the last one.
void    rotate(t_node **stack, char c)
{
    t_node  *temp;
    t_node  *last;
    
    temp = NULL;
    if (!stack || !*stack || !(*stack)->next)
        return ;
    temp = (*stack)->next;
    last = ft_lstNode(*stack);
    (*stack)->next = NULL;
    ft_nodeAdd_back(&last, *stack);
    *stack = temp;
    ft_printf("r%c\n", c);
}

void    rotate_no_print(t_node **stack)
{
    t_node  *temp;
    t_node  *last;
    
    temp = NULL;
    if (!stack || !*stack)
        return ;
    temp = (*stack)->next;
    last = ft_lstNode(*stack);
    (*stack)->next = NULL;
    ft_nodeAdd_back(&last, *stack);
    *stack = temp;
}
//shift two stacks at the same time.
void    double_rotate(t_node **stack_a, t_node **stack_b)
{
    rotate_no_print(stack_a);
    rotate_no_print(stack_b);
    ft_printf("rr\n");
}

//Shift down all elements of a stack by 1.
//The last element becomes the first one.
void    reverse_rotate(t_node **stack, char c)
{
    t_node  *last;
    t_node  *penultimate;

    last = NULL;
    penultimate = NULL;
    if (!stack || !*stack)
        return ;
    last = ft_lstNode(*stack);
    penultimate = *stack;
    while(penultimate->next->next)
        penultimate = penultimate->next;
    penultimate->next = NULL;
    last->next = *stack;
    *stack = last;
    ft_printf("rr%c\n", c);
    
}
//rra and rrb at the same time.
void    double_reverse_rotate(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a, 'a');
    reverse_rotate(stack_b, 'b');
    ft_printf("rrr\n");
}
