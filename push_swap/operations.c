/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/12/19 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	ft_putstr_fd("sa\n", 1);
	g_operations++;
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	ft_putstr_fd("sb\n", 1);
	g_operations++;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;
	t_node	*second_b;

	if (stack_a->size >= 2)
	{
		first_a = stack_a->top;
		second_a = first_a->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		stack_a->top = second_a;
	}
	if (stack_b->size >= 2)
	{
		first_b = stack_b->top;
		second_b = first_b->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		stack_b->top = second_b;
	}
	ft_putstr_fd("ss\n", 1);
	g_operations++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (is_empty(stack_b))
		return ;
	value = pop(stack_b);
	push(stack_a, value);
	ft_putstr_fd("pa\n", 1);
	g_operations++;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (is_empty(stack_a))
		return ;
	value = pop(stack_a);
	push(stack_b, value);
	ft_putstr_fd("pb\n", 1);
	g_operations++;
}