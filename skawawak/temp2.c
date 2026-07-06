/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:48:17 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/05 22:32:09 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_square_root(int num)
{
	int	i;

	i = 1;
	{
		while (i * i < num)
			i++;
	}
	return (i);
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	chunk_size;

	chunk_size = find_square_root(count);
	pb_by_chunk(stack_a, stack_b, chunk_size);
	while (stack_b != NULL)
	{
		rb_to_top(stack_b, count, find_number(count));
		pa(stack_a, stack_b);
		count--;
	}
}

void	pb_by_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_size,
		int count)
{
	int		num_of_chunk;
	int		count_in_chunk;
	t_stack	*ptr;

	num_of_chunk = 1;
	ptr = stack_a;
	while (num_of_chunk <= chunk_size)
	{
		count_in_chunk = 0;
		while (count_in_chunk < chunk_size)
		{
			ptr = stack_a;
			while (ptr->value > num_of_chunk * chunk_size)
				ptr = ptr->next;
			ra_to_top(stack_a, count, find_number(count)); //ここのロジックを見直すところから
			pb(stack_a, stack_b);
			count_in_chunk++;
			ptr = stack_a;
		}
		num_of_chunk++;
	}
}
