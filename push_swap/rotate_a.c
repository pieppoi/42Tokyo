/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 10:49:54 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	stack_a->top = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("ra\n", 1);
	g_operations++;
}

void	rra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*second_last;

	if (stack_a->size < 2)
		return ;
	last = stack_a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
	ft_putstr_fd("rra\n", 1);
	g_operations++;
} 