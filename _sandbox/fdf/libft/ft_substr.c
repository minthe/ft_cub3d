/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 14:35:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2021/08/23 16:46:05 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	sub = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!sub)
		return (NULL);
	if (start >= ft_strlen(s))
		return (sub);
	ft_strlcpy(sub, (s + start), len + 1);
	return (sub);
}
