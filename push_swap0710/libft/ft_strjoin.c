/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:38:03 by hyoshida          #+#    #+#             */
/*   Updated: 2026/05/24 15:14:23 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*copy_s(char const	*c1, char const	*c2, char	*array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c1[i] != '\0')
	{
		array[j] = c1[i];
		i++;
		j++;
	}
	i = 0;
	while (c2[i] != '\0')
	{
		array[j] = c2[i];
		i++;
		j++;
	}
	array[j] = '\0';
	return (array);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	return (copy_s(s1, s2, arr));
}
