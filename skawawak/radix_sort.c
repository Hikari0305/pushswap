/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:50:49 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/13 23:30:24 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_bit_count(size_t num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (1);
	while ((num >> count) != 0)
		count++;
	return (count);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a,
		t_config *cfg)
{
	size_t	bit_idx;
	size_t	processed_count;
	size_t	bit_count;
	t_stack	*ptr;

	bit_count = get_bit_count(size_a - 1);
	bit_idx = 0;
	while (bit_idx < bit_count)
	{
		processed_count = 0;
		while (processed_count < size_a)
		{
			ptr = *stack_a;
			if (((ptr->value >> bit_idx) & 1) == 0)
				pb(stack_a, stack_b, cfg);
			else
				ra(stack_a, cfg);
			processed_count++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b, cfg);
		bit_idx++;
	}
}
