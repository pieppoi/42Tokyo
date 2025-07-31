/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 23:23:36 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_seven_or_more(t_stacks *stacks)
{
	quick_sort_large(stacks);
}

void	quick_sort_large(t_stacks *stacks)
{
	while (stacks->stack_a->size > 3)
	{
		push_smallest_to_b(stacks);
	}
	if (stacks->stack_a->size == 3)
		sort_three_elements(stacks);
	while (!is_empty(stacks->stack_b))
	{
		pa(stacks);
	}
}

void	push_smallest_to_b(t_stacks *stacks)
{
	int	min;
	int	position;

	min = get_min(stacks->stack_a);
	position = get_position(stacks->stack_a, min);
	while (position > 0)
	{
		if (position <= stacks->stack_a->size / 2)
		{
			ra(stacks);
			position--;
		}
		else
		{
			rra(stacks);
			position = (position + 1) % stacks->stack_a->size;
		}
	}
	pb(stacks);
}
