/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:57:26 by hyoshida          #+#    #+#             */
/*   Updated: 2026/07/19 09:55:47 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MODE_SIMPLE 0
# define MODE_MEDIUM 1
# define MODE_COMPLEX 2
# define MODE_ADAPTIVE 3

typedef struct s_config
{
	int	mode;
	int	is_bench;
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
	int	total;
}		t_config;

char	**prepare_arguments(int argc, char **argv);
double	compute_disorder(t_stack *stack_a);
int		add_to_array(int *array, int *count, char *arg);
int		check_flag(char *arg, t_config *cfg);
int		count_args(char **args);
int		error_exit(t_stack **stack);
int		ft_atoi_check(const char *str, int *result);
int		is_numeric(char *str);
int		select_adaptive_mode(t_config *cfg, double disorder);
size_t	*compress_coordinates(int *num, size_t count);
size_t	get_ceil_square_root(size_t num);
size_t	get_size(t_stack *stack);
size_t	get_value_idx(t_stack *stack, size_t num);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a,
			t_config *cfg);
void	free_args(char **args);
void	free_stack(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b, t_config *cfg);
void	pb(t_stack **stack_a, t_stack **stack_b, t_config *cfg);
void	print_benchmark(t_config *cfg, int mode, double disorder);
void	ra(t_stack **stack_a, t_config *cfg);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a,
			t_config *cfg);
void	rb(t_stack **stack_b, t_config *cfg);
void	rotate_a_to_top(t_stack **stack, size_t size_a, size_t target_idx,
			t_config *cfg);
void	rr(t_stack **stack_a, t_stack **stack_b, t_config *cfg);
void	rra(t_stack **stack_a, t_config *cfg);
void	rrb(t_stack **stack_b, t_config *cfg);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_config *cfg);
void	sa(t_stack *stack_a, t_config *cfg);
void	sb(t_stack *stack_b, t_config *cfg);
void	selection_sort(t_stack **stack_a, t_stack **stack_b, size_t size_a,
			t_config *cfg);
void	ss(t_stack *stack_a, t_stack *stack_b, t_config *cfg);
void	sort_for_high_disorder(t_stack **stack_a, t_stack **stack_b,
			size_t size_a, t_config *cfg);
void	sort_for_medium_disorder(t_stack **stack_a, t_stack **stack_b,
			size_t size_a, t_config *cfg);
#endif
