/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:07:22 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/20 17:09:04 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(int *x, int *y, int z)
{
	int	x_temp;
	int	y_temp;

	x_temp = *x;
	y_temp = *y;
	*x = (x_temp - y_temp) * cos(0.523599);
	*y = ((x_temp + y_temp) * sin(0.523599)) - (z * 3);
}
