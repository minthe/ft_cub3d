/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/09 16:19:51 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	draw_ln(t_var *var)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = var->plr->end_x - var->plr->pos_x;
	delta_y = var->plr->end_y - var->plr->pos_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = var->plr->pos_x;
	pixel_y = var->plr->pos_y;
	while (pixels)
	{
		img_pix_put(var, pixel_x, pixel_y, 0xFFFFFF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	ft_cast_rayz(t_var *var, double radians)
{
	double	angl_incr;
	double	angle;
	double	distance;
	double x;
	double y;
	double dx;
	double dy;
	double fov;

	fov = FOV;
	dx = cos(radians);
	dy = sin(radians);
	printf("%f dx\n", dx);
	printf("%f dx\n", dx);
	x = var->plr->pos_x;
	y = var->plr->pos_y;
	angl_incr = fov / 50;
	angle = var->plr->p_angle - FOV / 2;
	while(angle < var->plr->p_angle + FOV / 2)
	{
		x = var->plr->pos_x;
		y = var->plr->pos_y;
		distance = 0;
		while(distance < 1000)
		{
			if(ft_is_wall(var,x,y))
				break;
			img_pix_put(var, x, y, 0xFFFF00);
			x += dx;
			y += dy;
			distance +=1;
			angle += angl_incr;
		}
	}
}