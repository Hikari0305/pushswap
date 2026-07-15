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

static int has_duplicate_arr(int *array, int count, int num)
{
    int i = 0;
    while (i < count)
    {
        if (array[i] == num)
            return (1);
        i++;
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

int  add_to_array(int *array, int *count, char *arg)
{
    int value;

    if (is_numeric(arg) == 0 || ft_atoi_check(arg, &value) == 0)
        return (0);
    if (has_duplicate_arr(array, *count, value) == 1)
        return (0);
    array[*count] = value;
    (*count)++;
    return (1);
}

// argvを安全にmallocされた二次元配列としてコピーして返す
char	**prepare_arguments(int ac, char **av)
{
	char	**args;
	int		i;

	if (ac == 2)
		return (ft_split(av[1], ' '));	
	// 引数が複数の場合、av[1] から最後の引数までを malloc して詰め替える
	args = malloc(sizeof(char *) * (ac));
	if (!args)
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		args[i] = ft_strdup(av[i + 1]);
		if (!args[i])
		{
			// 途中で失敗したらそれまで確保した分を解放
			while (i > 0)
				free(args[--i]);
			free(args);
			return (NULL);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}
