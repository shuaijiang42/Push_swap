/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:03:54 by shujiang          #+#    #+#             */
/*   Updated: 2023/05/31 17:18:37 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*1.Isnot int 2.bigger than int 3.duplicate*/
/*contain one or more no number character*/
/*after strtol*/
#include "push_swap.h"


//Data cleaning, make sure it is a number less than 10 digit (digits of INT_MAX).
void	lenth_and_digit_check(const char *str)
{
	size_t	i;
	size_t n;
	
	i = 0;
	if (str[i] != '-' && str[i] != '+' )
		n = 10;
	else
	{
		n = 11;
		i += 1;
	}
	if (ft_strlen(str) > n)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i])
		i++;
	if (i != ft_strlen(str))
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}
								
//turn a string into long and check if it is inside the range of int
long	ft_atol_check_int_range(const char *str)
{
	long	temp;
	long	sign;
	long	result;

	temp = 0;
	sign = 1;
	lenth_and_digit_check(str);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-' )
		str++;
	while (*str >= '0' && *str <= '9')
	{
		temp = temp * 10 + *str - '0';
		str++;
	}
	result = sign * temp;
	if (result <= INT_MAX && result >= INT_MIN)
		return (result);
	write(2, "Error\n", 7);
	exit(1);
}

//Split argv by spc
char ***orgnize_input(int argc, char **argv)
{
	char ***input_list;
    int i;
	int j;

    i = 1;
	j = 0;
    if(!argv)
		return(NULL);
	input_list = (char ***)malloc(argc * sizeof(char **));
	if (!input_list)
		return (NULL);
	if(!argv[i])
	{
		write(2, "Error\n", 7);
		exit(1);
	}
    while (argv[i])
    {
		while(argv[i][j] == ' ')
			j++;
		if (j == (int)ft_strlen(argv[i]))
		{
			write(2, "Error\n", 7);
			exit(1);
		}
        input_list[i - 1] = ft_split(argv[i], ' ');
        i++;
    }
	input_list[i - 1] = NULL;
	return (input_list);
}

//check if all the datas on the list are legal. looking through all the datas
//if there is any ilegal one, report Error and exit.
void check_data(char ***data_list)
{
	int i;
    int j;

    i = 0;
    j = 0;
	if(!data_list)
	{
        write(2, "Error\n", 7);
	    exit(1);
    }	
	while(data_list[i])
    {
    	while(data_list[i][j])
    	{
			ft_atol_check_int_range(data_list[i][j]);
        	j++;
    	}
    	i++;
    	j = 0; 
    }
}
//creat a new node
t_node	*ft_newNode(int data)
{
	t_node *node;
	
	node = malloc(sizeof(t_node));
	if (!node)
		return(NULL);
	node->data = data;
	node->next = NULL;
	return(node);
}

//go to the bottom of the stack
t_node	*ft_lstNode(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	return (stack);
}
//add data to the bottom of the stack
void	ft_nodeAdd_back(t_node **stack, t_node *new)
{
	t_node	*node;
	
	if(stack && *stack)
	{
		node = *stack;
		node = ft_lstNode(node);
		node->next = new;
	}
	else
		*stack = new; 
}

t_node	*input_to_stack(char ***data_list)
{
	t_node *stack;
	t_node *new;
	
	int i;
    int j;

    i = 0;
    j = 0;
	stack = NULL;
	while(data_list[i])
    {	
    	while(data_list[i][j])
    	{	
			new = ft_newNode(ft_atoi(data_list[i][j]));
			ft_nodeAdd_back(&stack, new);
        	j++;
    	}
    	i++;
    	j = 0; 
    }
	return(stack);
}

void	check_repeat(t_node *stack)
{
	t_node *temp;
	
	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->data == stack->data)
			{
				write(2, "ERROR\n", 7);
				exit(1);
			}
			temp = temp->next;
		}
		stack = stack->next;
	}
}	


