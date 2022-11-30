/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:22:19 by vfuhlenb          #+#    #+#             */
/*   Updated: 2021/08/21 20:49:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
