/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:02:10 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/27 16:55:12 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flag(char *arg, t_config *cfg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		cfg->mode = MODE_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		cfg->mode = MODE_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		cfg->mode = MODE_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		cfg->mode = MODE_ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		cfg->is_bench = 1;
	else
		return (0);	// フラグじゃなくて数字の引数だった場合
    return (1);     // フラグを検知してモードを切り替えた場合
}

// 引数の文字列が全部でいくつあるか数える
static int count_args(char **args)
{
    int i = 0;
    while (args[i])
        i++;
    return (i);
}

static int  parse_args_to_array(char **args, int **num_array, int *count, t_config *cfg)
{
    int i;
    int max_size;

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

// 構造体の中身を安全に0リセットする関数
static	void	init_config(t_config *cfg)
{
	int		*ptr;
	size_t	i;

	ptr = (int *)cfg;
	i = 0;
	while (i < sizeof(t_config) / sizeof(int))//この構造体の中に、int の部屋が全部で何個あるかを計算sizeof(t_config) ➔ 構造体全体の合計サイズ（バイト数）sizeof(int) ➔ int 1個のサイズ（4バイト）仮に構造体全体のサイズが48バイトだとしたら、48/4=12個の部屋があることになる。つまり、「12回ループするよ」という意味になる
		ptr[i++] = 0;
	cfg->mode = MODE_ADAPTIVE;
}

static t_stack *array_to_stack(size_t *compressed, int count)
{
    t_stack *stack_a;
    t_stack *new_node;
    int     i;

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
	if (count == 0 || count == 1)
		return (free(num_array), NULL);
	compressed = compress_coordinates(num_array, (size_t)count);
	free(num_array);
	if (!compressed)
		return (NULL);
	stack_a = array_to_stack(compressed, count);
	free(compressed);
	return (stack_a);
}

static void	select_adaptive_mode(t_config *cfg, double disorder)
{
	if (cfg->mode != MODE_ADAPTIVE)
		return ;
	if (disorder < 0.2)
		cfg->mode = MODE_SIMPLE;
	else if (disorder >= 0.2 && disorder < 0.5)
		cfg->mode = MODE_MEDIUM;
	else
		cfg->mode = MODE_COMPLEX;
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_stack		*stack_a;
	t_stack		*stack_b;
	double		disorder;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	init_config(&cfg);
	stack_a = init_and_parse_a(argc, argv, &cfg);
	if (!stack_a)
		return (error_exit(&stack_a));
	disorder = compute_disorder(stack_a);
	select_adaptive_mode(&cfg, disorder);
	if (cfg.mode == MODE_SIMPLE)
		selection_sort(&stack_a, &stack_b, get_stack_size(stack_a), &cfg);
	else
		chunk_sort(&stack_a, &stack_b, get_stack_size(stack_a), &cfg);

	print_benchmark(&cfg, disorder);
	return (free_stack(&stack_b), free_stack(&stack_a), 0);
}
