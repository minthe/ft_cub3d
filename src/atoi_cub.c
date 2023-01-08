/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:20:50 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/08 15:02:34 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
int	atoi_cub(t_var *var, const char *str)
{
	int	sign;
	int	ret;

	ret = 0;
	sign = 1;
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
		else
			var->data->err_color = 20;
		str++;
	}
	return (limiter(ret * sign));
}
