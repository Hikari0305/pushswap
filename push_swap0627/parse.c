/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:01:30 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/27 17:24:00 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_duplicate(t_stack *stack, int num)
{
	while (stack != NULL)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_atoi_check(const char *str, int *result)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
	}
	*result = (int)(num * sign);
	return (1);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**prepare_arguments(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	char	**args;
	int		i;

	joined = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (free(joined), NULL);
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}

double	compute_disorder(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		mistakes;
	int		total_pairs;

	if (!stack_a || !stack_a->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while (i != NULL)
	{
		j = i->next;
	while (j != NULL)
		{
			total_pairs++;
			if (i->value > j->value) // 前の方が大きい＝間違い（mistake）
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}

// 1行分の命令カウントを綺麗に並べて出力する
static	void	print_op_row(char *name1, int count1, char *name2, int count2, char *name3, int count3)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name1, 2);
	ft_putnbr_fd(count1, 2);
	if (name2)
	{
		ft_putstr_fd(" | ", 2);
		ft_putstr_fd(name2, 2);
		ft_putnbr_fd(count2, 2);
	}
	if (name3)
	{
		ft_putstr_fd(" | ", 2);
		ft_putstr_fd(name3, 2);
		ft_putnbr_fd(count3, 2);
	}
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_config *cfg, double disorder)
{
	int	whole;
	int	decimals;

	if (!cfg || !cfg->is_bench)
		return ;
	whole = (int)(disorder * 100);//少数から整数にしてる
	decimals = (int)((disorder * 100 - whole) * 100 + 0.5);//小数点以下も100をかけてdecimalsにいれる（+0.5は四捨五入してる）
	if (decimals < 0) 
		decimals = -decimals;
	ft_putstr_fd("\n[bench] Disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (decimals < 10) ft_putstr_fd("0", 2); //小数点いかが３だったら45.3とならずに45.03と出力するように10より小さいときは0を挟む
	ft_putnbr_fd(decimals, 2);
	ft_putstr_fd("%\n[bench] Strategy: ", 2);
	if (cfg->mode == MODE_SIMPLE) ft_putstr_fd("Simple (O(n^2))\n", 2);
	else if (cfg->mode == MODE_MEDIUM) ft_putstr_fd("Medium (O(n_sqrt_n))\n", 2);
	else if (cfg->mode == MODE_COMPLEX) ft_putstr_fd("Complex (O(n log n))\n", 2);
	else ft_putstr_fd("Adaptive (Auto Selection)\n", 2);
	ft_putstr_fd("[bench] Total operations: ", 2);
	ft_putnbr_fd(cfg->total, 2);
	ft_putstr_fd("\n", 2);
	print_op_row("sa: ", cfg->sa, "sb: ", cfg->sb, "ss: ", cfg->ss);
	print_op_row("pa: ", cfg->pa, "pb: ", cfg->pb, NULL, 0);
	print_op_row("ra: ", cfg->ra, "rb: ", cfg->rb, "rr: ", cfg->rr);
	print_op_row("rra: ", cfg->rra, "rrb: ", cfg->rrb, "rrr: ", cfg->rrr);
	ft_putstr_fd("--------------------------\n", 2);
}
