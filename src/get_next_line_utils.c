/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:08:50 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 16:50:34 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
	{
		counter ++;
	}
	return (counter);
}

char	*ft_strdup_gnl(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen_gnl(s1);
	ptr = (char *)malloc(sizeof(const char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	total_len;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	ptr = (char *)malloc(sizeof(char) * (total_len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = ((char *)s2)[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (0);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s && i < len && start < ft_strlen_gnl(s))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
