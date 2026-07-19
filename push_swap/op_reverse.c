/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:58:41 by hyoshida          #+#    #+#             */
/*   Updated: 2026/07/19 09:55:41 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pure_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, t_config *cfg)
{
	pure_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	if (cfg && cfg->is_bench)
	{
		cfg->rra++;
		cfg->total++;
	}
}

void	rrb(t_stack **stack_b, t_config *cfg)
{
	pure_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	if (cfg && cfg->is_bench)
	{
		cfg->rrb++;
		cfg->total++;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_config *cfg)
{
	pure_reverse_rotate(stack_a);
	pure_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	if (cfg && cfg->is_bench)
	{
		cfg->rrr++;
		cfg->total++;
	}
}
