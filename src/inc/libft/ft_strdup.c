/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:33:04 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/11 17:22:20 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1);
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, len + 1);
	return (new);
}
