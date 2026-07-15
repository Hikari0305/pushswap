/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:35:43 by hyoshida          #+#    #+#             */
/*   Updated: 2026/05/24 14:19:43 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	fill_result(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		len = 0;
		while (s[i + len] != '\0' && s[i + len] != c)
			len++;
		result[j] = ft_substr(&s[i], 0, len);
		if (!result[j])
			return (0);
		i += len;
		j++;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;

	if (!s)
		return (NULL);
	arr = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_result(arr, s, c))
	{
		i = 0;
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (arr);
}
