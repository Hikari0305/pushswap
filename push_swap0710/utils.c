/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:30:42 by hyoshida          #+#    #+#             */
/*   Updated: 2026/07/10 17:30:43 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

int	error_exit(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	return (1);
}
