/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 12:10:27 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdest;

	csrc = (char *) src;
	cdest = (char *) dest;
	i = 0;
	if ((!csrc) && (!cdest))
		return (0);
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
		ft_memcpy(dst, src, buf_len);
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

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len + 1);
	return (new);
}