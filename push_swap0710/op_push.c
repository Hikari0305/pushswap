#include "push_swap.c"

void	pa(t_stack **stack_a, t_stack **stack_b, t_config *cfg)//Bの先頭をAの先頭におく
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
	if (cfg && cfg->is_bench) //cfgがちゃんと存在するか念のためかくにん && cfg->is_bench=1のとき
	{
		cfg->pa++;
		cfg->total++;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_config *cfg)//Aの先頭をBの先頭におく
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
	if (cfg && cfg->is_bench)
	{
		cfg->pb++;
		cfg->total++;
	}
}
