/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:33:40 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/12 09:25:36 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_value_idx(t_stack *stack, int num)
{
	size_t	idx;
	t_stack	*ptr;

	idx = 0;
	ptr = stack;
	while (ptr->value != num)
	{
		idx++;
		ptr = ptr->next;
	}
	return (idx);
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a,
		t_config *cfg)
{
	size_t	target;

	target = 1;
	while (size_a > 2)
	{
		rotate_a_to_top(stack_a, size_a, get_value_idx(*stack_a, target), cfg);
		pb(stack_a, stack_b, cfg);
		target++;
		size_a--;
	}
	if ((*stack_a)->value > ((*stack_a)->next->value))
		ra(stack_a, cfg);
	while (*stack_b != NULL)
		pa(stack_a, stack_b, cfg);
}

void	rotate_a_to_top(t_stack **stack, size_t size_a, size_t target_idx,
		t_config *cfg)
{
	size_t	rotate_count;

	rotate_count = 0;
	if (target_idx < (size_a + 1) / 2)
	{
		while (rotate_count < target_idx)
		{
			ra(stack, cfg);
			rotate_count++;
		}
	}
	else
	{
		while (rotate_count < size_a - target_idx)
		{
			rra(stack, cfg);
			rotate_count++;
		}
	}
}

