/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 09:24:56 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/13 21:35:03 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	*compress_coordinates(int *num, size_t count)
{
	size_t	*compressed;
	size_t	rank;
	size_t	current_idx;
	size_t	compare_idx;

	compressed = malloc(count * sizeof(size_t));
	if (!compressed)
		return (NULL);
	current_idx = 0;
	while (current_idx < count)
	{
		rank = 0;
		compare_idx = 0;
		while (compare_idx < count)
		{
			if (num[current_idx] > num[compare_idx])
				rank++;
			compare_idx++;
		}
		compressed[current_idx] = rank;
		current_idx++;
	}
	return (compressed);
}
