/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:15:07 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/19 10:08:48 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(int mode_original, int mode_selected)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (mode_original == MODE_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (mode_original == MODE_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (mode_original == MODE_COMPLEX)
		ft_putstr_fd("Complex / O(nlogn)\n", 2);
	else if (mode_original == MODE_ADAPTIVE)
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (mode_selected == MODE_SIMPLE)
			ft_putstr_fd("O(n^2)\n", 2);
		else if (mode_selected == MODE_MEDIUM)
			ft_putstr_fd("O(n√n)\n", 2);
		else if (mode_selected == MODE_COMPLEX)
			ft_putstr_fd("O(nlogn)\n", 2);
	}
}

static void	print_disorder_percent(double disorder)
{
	int	total_points;
	int	whole;
	int	decimals;

	total_points = (int)(disorder * 10000.0 + 0.5);
	whole = total_points / 100;
	decimals = total_points % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (decimals < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimals, 2);
	ft_putstr_fd("%\n", 2);
}

static void	putstr_and_nbr_fd_for_benchmark(const char *ptr1, const char *ptr2,
		int value, int fd)
{
	ft_putstr_fd((char *)ptr1, fd);
	ft_putstr_fd((char *)ptr2, fd);
	ft_putnbr_fd(value, fd);
	ft_putstr_fd("  ", fd);
}

static void	print_op_row(const char *n1, int v1, int v2, int v3)
{
	char	*a;
	char	*b;
	char	*s;
	char	*r;

	a = "a:  ";
	b = "b:  ";
	s = "s:  ";
	r = "r:  ";
	putstr_and_nbr_fd_for_benchmark(n1, a, v1, 2);
	putstr_and_nbr_fd_for_benchmark(n1, b, v2, 2);
	if (n1[0] == 's')
		putstr_and_nbr_fd_for_benchmark(n1, s, v3, 2);
	else if (n1[0] == 'r')
		putstr_and_nbr_fd_for_benchmark(n1, r, v3, 2);
}

void	print_benchmark(t_config *cfg, int mode, double disorder)
{
	if (!cfg || !cfg->is_bench)
		return ;
	print_disorder_percent(disorder);
	print_strategy(cfg->mode, mode);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(cfg->total, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	print_op_row("s", cfg->sa, cfg->sb, cfg->ss);
	print_op_row("p", cfg->pa, cfg->pb, 0);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	print_op_row("r", cfg->ra, cfg->rb, cfg->rr);
	print_op_row("rr", cfg->rra, cfg->rrb, cfg->rrr);
	ft_putstr_fd("\n", 2);
}
