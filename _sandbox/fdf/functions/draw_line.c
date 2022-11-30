/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:52:09 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/16 20:01:06 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	draw_line(t_fdf *data, t_point *p1, t_point *p2)
{
	t_draw	draw;

	draw.delta_x = p2->x - p1->x;
	draw.delta_y = p2->y - p1->y;
	draw.pixels = sqrt((draw.delta_x * draw.delta_x) \
	+ (draw.delta_y * draw.delta_y));
	draw.delta_x /= draw.pixels;
	draw.delta_y /= draw.pixels;
	draw.pixel_x = p1->x;
	draw.pixel_y = p1->y;
	while (draw.pixels)
	{
		my_mlx_pixel_put(data, draw.pixel_x, \
		draw.pixel_y, 0x00FF0000);
		draw.pixel_x += draw.delta_x;
		draw.pixel_y += draw.delta_y;
		--draw.pixels;
	}
	return (0);
}
