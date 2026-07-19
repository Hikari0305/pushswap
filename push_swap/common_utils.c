/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:13:44 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/19 09:55:36 by skawawak         ###   ########.fr       */
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

size_t	get_size(t_stack *stack)
{
	size_t	size;
	t_stack	*ptr;

	size = 0;
	ptr = stack;
	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}

size_t	get_ceil_square_root(size_t num)
{
	size_t	i;

	i = 1;
	while (i * i < num)
		i++;
	return (i);
}
