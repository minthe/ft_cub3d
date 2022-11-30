/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:55:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/20 17:08:38 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < data->win_size_x && y < data->win_size_y)
	{
		dst = data->image->addr + (y * data->image->line_length \
		+ x * (data->image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
