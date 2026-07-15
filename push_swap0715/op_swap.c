/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:13:23 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/27 17:15:45 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	pure_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(t_stack *stack_a, t_config *cfg)
{
	if (!stack_a || !stack_a->next)
		return ;
	pure_swap(stack_a);
	write(1, "sa\n", 3); // 操作名を出力
	if (cfg && cfg->is_bench)
	{
		cfg->sa++;// スコア表の sa の欄を+1
		cfg->total++;// スコア表の総合計を+1
	}
}

void	sb(t_stack *stack_b, t_config *cfg)
{
	if (!stack_b || !stack_b->next)
		return ;
	pure_swap(stack_b);
	write(1, "sb\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->sb++;
		cfg->total++;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_config *cfg)
{
	pure_swap(stack_a);
	pure_swap(stack_b);
	write(1, "ss\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->ss++;
		cfg->total++;
	}
}
