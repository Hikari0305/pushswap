/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:00:10 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/27 17:15:35 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pure_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **stack_a, t_config *cfg)
{
	pure_rotate(stack_a);
	write(1, "ra\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->ra++;
		cfg->total++;
	}
}

void	rb(t_stack **stack_b, t_config	*cfg)
{
	pure_rotate(stack_b);
	write(1, "rb\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->rb++;
		cfg->total++;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_config *cfg)
{
	pure_rotate(stack_a);
	pure_rotate(stack_b);
	write(1, "rr\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->rr++;
		cfg->total++;
	}
}
