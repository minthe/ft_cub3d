/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peeks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:09:12 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/14 18:38:47 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//function that checks for valid ident character
int	is_ident_char(char c)
{
	if (c == 67 || c == 70 || \
		(c >= 78 && c <= 79) || c == 83 || c == 87)
		return (1);
	return (0);
}

//function that checks for valid map character
int	is_map_char(char c)
{
	if (c == 32 || (c >= 48 && c <= 49) || \
		c == 78 || c == 79 || c == 83 || c == 87)
		return (1);
	return (0);
}

//function that checks for valid map characters
int	only_map_char(const char *str)
{
	while (*str)
	{
		if (*str != 32 && !(*str >= 48 && *str <= 49) && \
			!(*str >= 78 && *str <= 79) && *str != 83 && *str != 87)
			return (0);
		str++;
	}
	return (1);
}
