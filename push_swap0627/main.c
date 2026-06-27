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

// ポインタで構造体（cfg）を直接受け取る
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

static int	add_to_stack(t_stack **stack, char *arg)
{
	int		value;
	t_stack	*new_node;

	if (is_numeric(arg) == 0 || ft_atoi_check(arg, &value) == 0)
		return (0);
	if (has_duplicate(*stack, value) == 1)
		return (0);
	new_node = ft_lstnew(value);
	if (!new_node)
		return (0);
	ft_lstadd_back(stack, new_node);
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

int	main(int argc, char **argv)
{
	char		**args;
	int			i;
	t_config	cfg;
	t_stack		*stack_a;
	t_stack		*stack_b;
	double		disorder;

	stack_a = NULL;
	stack_b = NULL;
	mode = MODE_ADAPTIVE;
	is_bench = 0;
	if (argc == 1)
		return (0);
	init_config(&cfg);
	args = prepare_arguments(argc, argv);
	if (!args)
		return (0);
	i = 0;
	while (args[i] != NULL)
	{
		if (check_flag(args[i], &cfg))
		{
			i++;
			continue ;
		}
		if (add_to_stack(&stack_a, args[i]) == 0)
		{
			free_args(args);
			return (error_exit(&stack_a));
		}
		i++;
	}
	free_args(args);
	//数字が0個または1個ならソート不要なので何もせず終了
	if (!stack_a || !stack_a->next)
	{
		free_stack(&stack_a);
		return (0);
	}
	//何か操作をする前の、完全な初期状態の不規則度を測定
	disorder = compute_disorder(stack_a);
	// if (mode == MODE_SIMPLE)
	//     solve_simple(&stack_a, &stack_b);
	// else if ...
	print_benchmark(&cfg, disorder);//スコア表示
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}
