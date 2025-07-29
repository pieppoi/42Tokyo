/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/12/19 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!check_digit(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0')
			return (0);
		if ((argv[i][0] == '-' && num > 0) || (argv[i][0] != '-' && num < 0))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size <= 1)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (is_empty(stack))
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (is_empty(stack))
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;

	position = 0;
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

void	print_operations(void)
{
	(void)0;
} 