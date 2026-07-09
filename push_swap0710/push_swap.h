/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:57:26 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/27 16:46:17 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

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

typedef struct  s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// ユーティリティ・パース系
void	free_stack(t_stack **stack);
int		error_exit(t_stack **stack);
void	free_args(char **args);
int		has_duplicate(t_stack *stack, int num);
int		ft_atoi_check(const char *str, int *result);
int		is_numeric(char *str);
char	**prepare_arguments(int argc, char **argv);
double	compute_disorder(t_stack *stack_a);
void	print_benchmark(t_config *cfg, double disorder);

// Libft代用（実際の環境に合わせて用意してください）
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

// 命令関数（すべてに t_config *cfg を追加！）
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

#endif
