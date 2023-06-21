/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:22:59 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/21 17:38:28 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of a stack.
void    swap(t_node **stack, char c)
{
    t_node *first = *stack;
    t_node *second = first->next;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first->next = second->next;
    first->prev = second;
    second->next = first;
    second->prev = NULL;
    *stack = second;
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
    t_node *temp = *stack1;
    
    if (!stack1 || !*stack1)
        return;
    if (temp->next)
        temp->next->prev = NULL;
    *stack1 = temp->next;
    temp->next = *stack2;
    temp->prev = NULL;
    if (*stack2)
        (*stack2)->prev = temp;
    *stack2 = temp;
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
    last = ft_lstNode(*stack);
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
    ft_printf("r%c\n", c);
}

void    rotate_no_print(t_node **stack)
{
    t_node  *temp;
    t_node  *last;
     temp = NULL;
    if (!stack || !*stack || !(*stack)->next)
        return ;
    last = ft_lstNode(*stack);
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
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
/* void    reverse_rotate(t_node **stack, char c)
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
    
} */

void    reverse_rotate(t_node **stack, char c)
{
    t_node  *last;
    t_node  *penultimate;

    last = NULL;
    penultimate = NULL;
    if (!stack || !*stack || !(*stack)->next)
        return ;
    last = ft_lstNode(*stack);
    penultimate = last->prev;
    penultimate->next = NULL;
    last->prev = NULL; 
    last->next = *stack;
    (*stack)->prev = last;
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
