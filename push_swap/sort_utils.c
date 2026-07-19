/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 03:20:28 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/19 09:55:53 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	*compress_coordinates(int *num, size_t count)
{
	size_t	*compressed;
	size_t	rank;
	size_t	current_idx;
	size_t	compare_idx;

	compressed = malloc(count * sizeof(size_t));
	if (!compressed)
		return (NULL);
	current_idx = 0;
	while (current_idx < count)
	{
		rank = 0;
		compare_idx = 0;
		while (compare_idx < count)
		{
			if (num[current_idx] > num[compare_idx])
				rank++;
			compare_idx++;
		}
		compressed[current_idx] = rank;
		current_idx++;
	}
	return (compressed);
}

double	compute_disorder(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		mistakes;
	int		total_pairs;

	if (!stack_a || !stack_a->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}

int	select_adaptive_mode(t_config *cfg, double disorder)
{
	int	mode;

	if (cfg->mode != MODE_ADAPTIVE)
		return (cfg->mode);
	if (disorder < 0.2)
		mode = MODE_SIMPLE;
	else if (disorder >= 0.2 && disorder < 0.5)
		mode = MODE_MEDIUM;
	else
		mode = MODE_COMPLEX;
	return (mode);
}

void	sort_for_medium_disorder(t_stack **stack_a, t_stack **stack_b,
		size_t size_a, t_config *cfg)
{
	if (size_a < 20)
		selection_sort(stack_a, stack_b, size_a, cfg);
	else
		chunk_sort(stack_a, stack_b, size_a, cfg);
}

void	sort_for_high_disorder(t_stack **stack_a, t_stack **stack_b,
		size_t size_a, t_config *cfg)
{
	if (size_a < 20)
		selection_sort(stack_a, stack_b, size_a, cfg);
	else
		radix_sort(stack_a, stack_b, size_a, cfg);
}
