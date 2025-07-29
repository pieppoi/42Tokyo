/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 10:50:25 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first_a;
	t_node	*last_a;
	t_node	*first_b;
	t_node	*last_b;

	if (stack_a->size >= 2)
	{
		first_a = stack_a->top;
		last_a = stack_a->top;
		while (last_a->next)
			last_a = last_a->next;
		stack_a->top = first_a->next;
		first_a->next = NULL;
		last_a->next = first_a;
	}
	if (stack_b->size >= 2)
	{
		first_b = stack_b->top;
		last_b = stack_b->top;
		while (last_b->next)
			last_b = last_b->next;
		stack_b->top = first_b->next;
		first_b->next = NULL;
		last_b->next = first_b;
	}
	ft_putstr_fd("rr\n", 1);
	g_operations++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*last_a;
	t_node	*second_last_a;
	t_node	*last_b;
	t_node	*second_last_b;

	if (stack_a->size >= 2)
	{
		last_a = stack_a->top;
		second_last_a = NULL;
		while (last_a->next)
		{
			second_last_a = last_a;
			last_a = last_a->next;
		}
		second_last_a->next = NULL;
		last_a->next = stack_a->top;
		stack_a->top = last_a;
	}
	if (stack_b->size >= 2)
	{
		last_b = stack_b->top;
		second_last_b = NULL;
		while (last_b->next)
		{
			second_last_b = last_b;
			last_b = last_b->next;
		}
		second_last_b->next = NULL;
		last_b->next = stack_b->top;
		stack_b->top = last_b;
	}
	ft_putstr_fd("rrr\n", 1);
	g_operations++;
} 