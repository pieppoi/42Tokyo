/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/12/19 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*create_stack(void);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	clear_stack(t_stack *stack);
int		is_empty(t_stack *stack);
int		peek(t_stack *stack);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

int		validate_input(int argc, char **argv);
int		check_duplicates(t_stack *stack);

void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_medium_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_large_stack(t_stack *stack_a, t_stack *stack_b);
void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b,
			int min_range, int max_range);

int		is_sorted(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
void	print_operations(void);

extern int	g_operations;

#endif 