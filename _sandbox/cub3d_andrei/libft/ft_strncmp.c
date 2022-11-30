/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:18:25 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/30 17:06:41 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		result;

	result = 0;
	index = 0;
	while (index < n)
	{
		result = (unsigned char)s1[index] - (unsigned char)s2[index];
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
			break ;
		index++;
	}
	return (result);
}
