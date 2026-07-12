/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:48:17 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/12 12:08:54 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_ceil_square_root(size_t num)
{
	size_t	i;

	i = 1;
	while (i * i < num)
		i++;
	return (i);
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a,
		t_config *cfg)
{
	size_t	target;
	size_t	size_b;

	push_chunk_to_b(stack_a, stack_b, size_a, cfg);
	target = size_a;
	size_b = size_a;
	while (*stack_b != NULL)
	{
		rotate_b_to_top(stack_b, size_b, get_value_idx(*stack_b, target), cfg);
		pa(stack_a, stack_b, cfg);
		target--;
		size_b--;
	}
}

void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, size_t size_a,
		t_config *cfg)
{
	size_t	chunk_number;
	size_t	count_in_chunk;
	size_t	chunk_size;
	size_t	chunk_capacity;

	chunk_size = get_ceil_square_root(size_a);
	chunk_capacity = chunk_size;
	chunk_number = 1;
	while (chunk_number <= chunk_size)
	{
		count_in_chunk = 0;
		while (count_in_chunk < chunk_capacity && *stack_a != NULL)
		{
			rotate_a_to_top(stack_a, size_a, get_nearest_value_idx(*stack_a,
					size_a, (chunk_size * chunk_number)), cfg);
			pb(stack_a, stack_b, cfg);
			count_in_chunk++;
			size_a--;
		}
		chunk_number++;
	}
}

size_t	get_nearest_value_idx(t_stack *stack, size_t stack_size, size_t max)
{
	size_t	top;
	size_t	bottom;
	t_stack	*ptr;
	size_t	idx;
	size_t	count;

	top = 0;
	bottom = 0;
	idx = 0;
	count = 0;
	ptr = stack;
	while ((idx < stack_size))
	{
		if ((ptr->value <= max))
		{
			bottom = idx;
			if (count == 0)
				top = idx;
			count++;
		}
		ptr = ptr->next;
		idx++;
	}
	return (compare_distance_from_edge(top, bottom, stack_size));
}

size_t	compare_distance_from_edge(size_t top, size_t bottom, size_t stack_size)
{
	if (top <= (stack_size - bottom))
		return (top);
	else
		return (bottom);
}

void	rotate_b_to_top(t_stack **stack, size_t size_b, size_t target_idx,
		t_config *cfg)
{
	size_t	rotate_count;

	rotate_count = 0;
	if (target_idx < (size_b + 1) / 2)
	{
		while (rotate_count < target_idx)
		{
			rb(stack, cfg);
			rotate_count++;
		}
	}
	else
	{
		while (rotate_count < size_b - target_idx)
		{
			rrb(stack, cfg);
			rotate_count++;
		}
	}
}
