#include "push_swap.h"

double	compute_disorder(t_stack *stack_a) //不規則度をはかる
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
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}

static void	print_strategy(int mode)
{
	ft_putstr_fd("[bench] Strategy: ", 2);
	if (mode == MODE_SIMPLE)
		ft_putstr_fd("Simple (O(n^2))\n", 2);
	else if (mode == MODE_MEDIUM)
		ft_putstr_fd("Medium (O(n_sqrt_n))\n", 2);
	else if (mode == MODE_COMPLEX)
		ft_putstr_fd("Complex (O(n log n))\n", 2);
	else
		ft_putstr_fd("Adaptive (Auto Selection)\n", 2);
}

static void	print_disorder_percent(double disorder)
{
	int	total_points;
	int	whole;
	int	decimals;

	// 最初から10000倍（%にするために100倍、さらに小数点2桁のために100倍）する
	total_points = (int)(disorder * 10000.0 + 0.5);
	whole = total_points / 100;    // 上の桁（例：45）
	decimals = total_points % 100; // 下の桁（例：32）
	ft_putstr_fd("\n[bench] Disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (decimals < 10)//45.03など間に0が入る時のため
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimals, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_benchmark(t_config *cfg, double disorder)
{
	if (!cfg || !cfg->is_bench)
		return ;
	print_disorder_percent(disorder);
	print_strategy(cfg->mode);
	ft_putstr_fd("[bench] Total operations: ", 2);
	ft_putnbr_fd(cfg->total, 2);
	ft_putstr_fd("\n", 2);
	print_op_row("sa: ", cfg->sa, "sb: ", cfg->sb, "ss: ", cfg->ss);
	print_op_row("pa: ", cfg->pa, "pb: ", cfg->pb, NULL, 0);
	print_op_row("ra: ", cfg->ra, "rb: ", cfg->rb, "rr: ", cfg->rr);
	print_op_row("rra: ", cfg->rra, "rrb: ", cfg->rrb, "rrr: ", cfg->rrr);
	ft_putstr_fd("--------------------------\n", 2);
}
