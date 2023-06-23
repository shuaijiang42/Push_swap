/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:03:54 by shujiang          #+#    #+#             */
/*   Updated: 2023/06/23 19:35:05 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Data cleaning, make sure it is a number 
//less than 10 digit (digits of INT_MAX).
void	lenth_and_digit_check(const char *str)
{
	size_t	i;
	size_t	n;

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

//check if all the datas on the list are legal. looking through all the datas
//if there is any ilegal one, report Error and exit.
void	check_data(char ***data_list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!data_list)
	{
		write(2, "Error\n", 7);
		exit(1);
	}	
	while (data_list[i])
	{
		while (data_list[i][j])
		{
			ft_atol_check_int_range(data_list[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_repeat(t_node *stack)
{
	t_node	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->data == stack->data)
			{
				write(2, "Error\n", 7);
				free_stack(&stack);
				exit(1);
			}
			temp = temp->next;
		}
		stack = stack->next;
	}
}
