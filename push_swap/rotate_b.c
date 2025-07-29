/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 10:50:07 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	stack_b->top = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("rb\n", 1);
	g_operations++;
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*second_last;

	if (stack_b->size < 2)
		return ;
	last = stack_b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
	ft_putstr_fd("rrb\n", 1);
	g_operations++;
} 