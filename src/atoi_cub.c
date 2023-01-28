/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:20:50 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 12:33:28 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// checks if character is a space
static int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == ' '))
		return (1);
	else
		return (0);
}

static int	limiter(int i)
{
	if (i < 0)
		return (0);
	else if (i > 255)
		return (255);
	return (i);
}

// takes a string and converts it into an integer
int	atoi_cub(const char *str, int sign, int ret, t_var *var)
{
	hasdigits(var, str, var->data->color_c);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
			ret = (ret * 10) + (*str - '0');
		else if (!ft_isdigit(*str) && !ft_isspace(*str))
		{
			if (var->data->color_c == 'C')
				error_msg_exit(var, "C: invalid color characters");
			else
				error_msg_exit(var, "F: invalid color characters");
		}
		str++;
	}
	return (limiter(ret * sign));
}
