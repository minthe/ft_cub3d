/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:40:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2021/08/23 17:55:25 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t num)
{
	size_t	i;

	i = 0;
	if (!dest && !source)
		return (NULL);
	if (dest > source)
	{
		while (num)
		{
			num--;
			((unsigned char *)dest)[num] = ((unsigned char *)source)[num];
		}
	}
	else
	{
		while (num)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
			i++;
			num--;
		}
	}
	return (dest);
}
