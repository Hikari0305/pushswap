/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 09:24:56 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/12 09:25:31 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*compress_coordinates(int *num, size_t count)
{
	int		*compressed;
	size_t	rank;
	size_t	current_idx;
	size_t	compare_idx;

	compressed = malloc(count * sizeof(int));
	if (!compressed)
		return (NULL);
	current_idx = 0;
	while (current_idx < count)
	{
		rank = 1;
		compare_idx = 0;
		while (compare_idx < count)
		{
			if (num[current_idx] > num[compare_idx])
				rank++;
			compare_idx++;
		}
		compressed[current_idx] = (int)rank;
		current_idx++;
	}
	return (compressed);
}
