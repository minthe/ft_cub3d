/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:40:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/22 13:32:26 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c) && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		end;
	int		start;
	char	**sentence;

	if (!s)
		return (NULL);
	x = 0;
	start = 0;
	sentence = ft_calloc(ft_countwords((char *)s, c) + 1, sizeof(char *));
	if (!sentence)
		return (NULL);
	while (s[start])
	{
		while ((s[start] == c) && s[start])
			start++;
		end = start;
		while ((s[end] != c) && s[end])
			end++;
		if (s[start])
			sentence[x] = ft_substr(s, start, end - start);
		x++;
		start = end;
	}
	return (sentence);
}
