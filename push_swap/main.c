/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:02:10 by hyoshida          #+#    #+#             */
/*   Updated: 2026/07/19 09:55:37 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_args_to_array(char **args, int **num_array, int *count,
		t_config *cfg)
{
	int	i;
	int	max_size;

	if (!strategy_selector_check(args))
		return (free_args(args), 0);
	max_size = count_args(args);
	*num_array = malloc(max_size * sizeof(int));
	if (!*num_array)
		return (free_args(args), 0);
	i = 0;
	*count = 0;
	while (args[i] != NULL)
	{
		if (check_flag(args[i], cfg))
		{
			i++;
			continue ;
		}
		if (add_to_array(*num_array, count, args[i]) == 0)
			return (free(*num_array), free_args(args), 0);
		i++;
	}
	free_args(args);
	return (1);
}

static void	init_config(t_config *cfg)
{
	int		*ptr;
	size_t	i;

	ptr = (int *)cfg;
	i = 0;
	while (i < sizeof(t_config) / sizeof(int))
		ptr[i++] = 0;
	cfg->mode = MODE_ADAPTIVE;
}

static t_stack	*array_to_stack(size_t *compressed, int count)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < count)
	{
		new_node = ft_lstnew((int)compressed[i]);
		if (!new_node)
		{
			free_stack(&stack_a);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

static t_stack	*init_and_parse_a(int argc, char **argv, t_config *cfg)
{
	char	**args;
	int		*num_array;
	int		count;
	size_t	*compressed;
	t_stack	*stack_a;

	num_array = NULL;
	args = prepare_arguments(argc, argv);
	if (!args || !parse_args_to_array(args, &num_array, &count, cfg))
		return (NULL);
	if (count == 0)
		return (free(num_array), NULL);
	compressed = compress_coordinates(num_array, (size_t)count);
	free(num_array);
	if (!compressed)
		return (NULL);
	stack_a = array_to_stack(compressed, count);
	free(compressed);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_stack		*stack_a;
	t_stack		*stack_b;
	double		disorder;
	int			mode_selected;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	init_config(&cfg);
	stack_a = init_and_parse_a(argc, argv, &cfg);
	if (!stack_a)
		return (error_exit(&stack_a));
	disorder = compute_disorder(stack_a);
	mode_selected = select_adaptive_mode(&cfg, disorder);
	if (disorder != 0 && mode_selected == MODE_SIMPLE)
		selection_sort(&stack_a, &stack_b, get_size(stack_a), &cfg);
	else if (disorder != 0 && mode_selected == MODE_MEDIUM)
		sort_for_medium_disorder(&stack_a, &stack_b, get_size(stack_a), &cfg);
	else if (disorder != 0 && mode_selected == MODE_COMPLEX)
		sort_for_high_disorder(&stack_a, &stack_b, get_size(stack_a), &cfg);
	print_benchmark(&cfg, mode_selected, disorder);
	return (free_stack(&stack_b), free_stack(&stack_a), 0);
}
