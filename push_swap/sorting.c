/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/12/19 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = peek(stack_a);
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first > second && second < third && third > first)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && third < first)
		ra(stack_a);
	else if (first < second && second > third && third > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && third < first)
		rra(stack_a);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		sort_small_stack(stack_a, stack_b);
	else if (stack_a->size <= 5)
		sort_medium_stack(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->size == 2)
	{
		if (peek(stack_a) > stack_a->top->next->value)
			sa(stack_a);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
}

static void	move_to_top(t_stack *stack_a, int position)
{
	int	i;

	if (position <= stack_a->size / 2)
	{
		i = 0;
		while (i < position)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack_a->size - position)
		{
			rra(stack_a);
			i++;
		}
	}
}

void	sort_medium_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	position;

	while (stack_a->size > 3)
	{
		min = get_min(stack_a);
		position = get_position(stack_a, min);
		if (position == 0)
			pb(stack_a, stack_b);
		else
		{
			move_to_top(stack_a, position);
			pb(stack_a, stack_b);
		}
	}
	sort_small_stack(stack_a, stack_b);
	while (!is_empty(stack_b))
		pa(stack_a, stack_b);
}

static void	push_chunks(t_stack *stack_a, t_stack *stack_b,
		int chunk_size, int min, int max)
{
	int	range;
	int	i;

	range = (max - min) / chunk_size;
	i = 0;
	while (i < chunk_size && !is_empty(stack_a))
	{
		push_chunk_to_b(stack_a, stack_b, min + i * range,
			min + (i + 1) * range);
		i++;
	}
	while (!is_empty(stack_a))
		pb(stack_a, stack_b);
}

static void	sort_back(t_stack *stack_a, t_stack *stack_b)
{
	int	max_b;
	int	pos;

	while (!is_empty(stack_b))
	{
		max_b = get_max(stack_b);
		pos = get_position(stack_b, max_b);
		if (pos <= stack_b->size / 2)
		{
			while (pos > 0)
			{
				rb(stack_b);
				pos--;
			}
		}
		else
		{
			while (pos < stack_b->size)
			{
				rrb(stack_b);
				pos++;
			}
		}
		pa(stack_a, stack_b);
	}
}

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	min;
	int	max;

	if (stack_a->size <= 100)
		chunk_size = stack_a->size / 4;
	else
		chunk_size = stack_a->size / 8;
	min = get_min(stack_a);
	max = get_max(stack_a);
	push_chunks(stack_a, stack_b, chunk_size, min, max);
	sort_back(stack_a, stack_b);
}

void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b,
		int min_range, int max_range)
{
	t_node	*current;
	int		position;
	int		i;

	while (1)
	{
		current = stack_a->top;
		position = 0;
		i = 0;
		while (current)
		{
			if (current->value >= min_range && current->value <= max_range)
			{
				move_to_top(stack_a, position);
				pb(stack_a, stack_b);
				return ;
			}
			current = current->next;
			position++;
		}
		break ;
	}
} 