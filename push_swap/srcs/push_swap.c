/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 23:23:16 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	cleanup_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			clear_stack(stacks->stack_a);
		if (stacks->stack_b)
			clear_stack(stacks->stack_b);
		free(stacks);
	}
}

static void	init_and_validate(t_stacks *stacks, int argc, char **argv)
{
	init_stack(stacks->stack_a, argc, argv);
	if (check_duplicates(stacks->stack_a))
	{
		cleanup_stacks(stacks);
		handle_error();
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	if (!validate_input(argc, argv))
		handle_error();
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		handle_error();
	stacks->stack_a = create_stack();
	stacks->stack_b = create_stack();
	if (!stacks->stack_a || !stacks->stack_b)
	{
		cleanup_stacks(stacks);
		handle_error();
	}
	init_and_validate(stacks, argc, argv);
	if (!is_sorted(stacks->stack_a))
		sort_stack(stacks);
	cleanup_stacks(stacks);
	return (0);
}
