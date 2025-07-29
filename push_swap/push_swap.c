/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 10:50:38 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_operations = 0;

static void	init_stack(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		push(stack_a, ft_atoi(argv[i]));
		i--;
	}
}

static void	handle_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	cleanup_stacks(t_stack *stack_a, t_stack *stack_b)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
}

static void	process_stack(t_stack *stack_a, t_stack *stack_b)
{
	init_stack(stack_a, stack_a->size + 1, NULL);
	if (check_duplicates(stack_a))
	{
		cleanup_stacks(stack_a, stack_b);
		handle_error();
	}
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!validate_input(argc, argv))
		handle_error();
	stack_a = create_stack();
	stack_b = create_stack();
	if (!stack_a || !stack_b)
	{
		cleanup_stacks(stack_a, stack_b);
		handle_error();
	}
	init_stack(stack_a, argc, argv);
	if (check_duplicates(stack_a))
	{
		cleanup_stacks(stack_a, stack_b);
		handle_error();
	}
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	cleanup_stacks(stack_a, stack_b);
	return (0);
}