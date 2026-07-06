/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:33:40 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/05 17:13:28 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*num_list_comp(int *num, size_t count)
{
	int		*list;
	size_t	order;
	size_t	i;
	size_t	j;

	list = malloc(count * sizeof(int));
	if (!list)
		return (NULL);
	i = 0;
	while (i < count)
	{
		order = 0;
		j = 0;
		while (j < count)
		{
			if (num[i] > num[j])
				order++;
			j++;
		}
		list[i] = (int)(order + 1);
		i++;
	}
	return (list);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	i;

	i = 1;
	while (count > 2)
	{
		rotate_to_top(stack_a, count, find_number(stack_a, i));
		pb(stack_a, stack_b);
		i++;
		count--;
	}
	if (stack_a->value > ((stack_a->next)->value))
		ra(stack_a);
	while (stack_b != NULL)
		pa(stack_a, stack_b);
}

void	rotate_to_top(t_stack *stack, int count, int j)
{
	int	k;

	k = 0;
	if (j <= (count + 1) / 2)
		while (k < j)
		{
			ra(stack);
			k++;
		}
	else
		while (k < count - j)
		{
			rra(stack);
			k++;
		}
}

int	find_number(t_stack *stack, int num)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = stack;
	while (ptr->value != num)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
