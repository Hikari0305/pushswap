/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:31:56 by hyoshida          #+#    #+#             */
/*   Updated: 2026/07/19 09:55:39 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, t_config *cfg)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->pa++;
		cfg->total++;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_config *cfg)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->pb++;
		cfg->total++;
	}
}
