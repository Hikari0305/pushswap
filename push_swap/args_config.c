/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 09:17:59 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/19 09:55:33 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flag(char *arg, t_config *cfg)
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
		return (0);
	return (1);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	strategy_selector_check(char **args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i] != NULL)
	{
		if ((ft_strcmp(args[i], "--simple") == 0) || (ft_strcmp(args[i],
					"--medium") == 0) || (ft_strcmp(args[i], "--complex") == 0)
			|| (ft_strcmp(args[i], "--adaptive") == 0))
		{
			count++;
			if (count > 1)
				return (0);
		}
		i++;
	}
	return (1);
}
