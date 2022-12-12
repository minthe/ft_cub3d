/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 11:38:50 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//function that checks for whitespace character
static int	is_whitespace_char(char c)
{
	if (c != 32 && !(c >= 9 && c <= 13))
		return (0);
	return (1);
}

static void	*ft_memcpy_cub(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*csrc;
	char	*cdest;

	csrc = (char *) src;
	cdest = (char *) dest;
	i = 0;
	j = 0;
	if ((!csrc) && (!cdest))
		return (0);
	while (i < n)
	{
		if (!is_whitespace_char(&csrc[i]))
			cdest[j] = csrc[i];
		i++;
		j++;
	}
	return (dest);
}

static size_t	ft_strlcpy_cub(char *dst, const char *src, size_t dstsize)
{
	size_t	buf_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize)
	{
		if (src_len >= dstsize)
			buf_len = dstsize - 1;
		else
			buf_len = src_len;
		ft_memcpy_cub(dst, src, buf_len);
		dst[buf_len] = '\0';
	}
	return (src_len);
}

static size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
	{
		counter ++;
	}
	return (counter);
}

char	*ft_strdup_cub(const char *s1)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1);
	new = ft_ca
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy_cub(new, s1, len + 1);
	return (new);
}