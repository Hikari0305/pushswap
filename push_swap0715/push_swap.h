/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:57:26 by hyoshida          #+#    #+#             */
/*   Updated: 2026/07/10 17:31:00 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include "libft/libft.h"

# define MODE_SIMPLE   0
# define MODE_MEDIUM   1
# define MODE_COMPLEX  2
# define MODE_ADAPTIVE 3

typedef struct s_config
{
	int	mode;// MODE_ADAPTIVE などの選択されたモード
	int	is_bench;// --bench フラグが立っていたら 1、それ以外は 0
	int	sa;
	int	sb;
	int	ss;
	int	pa;	
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;// 総操作回数の合計
}	t_config;

// ユーティリティ・パース系
void	free_stack(t_stack **stack);
int		error_exit(t_stack **stack);
void	free_args(char **args);
int		has_duplicate(t_stack *stack, int num);
int		ft_atoi_check(const char *str, int *result);
int		is_numeric(char *str);
int 	add_to_array(int *array, int *count, char *arg);
double	compute_disorder(t_stack *stack_a);
void	print_benchmark(t_config *cfg, double disorder);


// 命令関数
void	sa(t_stack *stack_a, t_config *cfg);
void	sb(t_stack *stack_b, t_config *cfg);
void	ss(t_stack *stack_a, t_stack *stack_b, t_config *cfg);
void	pa(t_stack **stack_a, t_stack **stack_b, t_config *cfg);
void	pb(t_stack **stack_a, t_stack **stack_b, t_config *cfg);
void	ra(t_stack **stack_a, t_config *cfg);
void	rb(t_stack **stack_b, t_config *cfg);
void	rr(t_stack **stack_a, t_stack **stack_b, t_config *cfg);
void	rra(t_stack **stack_a, t_config *cfg);
void	rrb(t_stack **stack_b, t_config *cfg);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_config *cfg);

void	rotate_a_to_top(t_stack **stack, size_t size_a, size_t target_idx, t_config *cfg);
void	selection_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a, t_config *cfg);
size_t	*compress_coordinates(int *num, size_t count);
char    **prepare_arguments(int argc, char **argv);
size_t  get_stack_size(t_stack *stack);
void	print_op_row(const char *n1, int v1, const char *n2, int v2, const char *n3, int v3);

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a, t_config *cfg);
size_t	get_value_idx(t_stack *stack, int num);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a,
		t_config *cfg);

#endif
