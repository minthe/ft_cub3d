/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/15 21:45:35 by dimbrea          ###   ########.fr       */
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

	delta_x = var->map->wall_ex - var->map->wall_sx;
	delta_y = var->map->wall_ey - var->map->wall_sy;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = var->map->wall_sx;
	pixel_y = var->map->wall_sy;
	while (pixels)
	{
		img_pix_put(var, pixel_x, pixel_y, 0xFFFFFF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	ft_get_dist(t_var *var)
{
	double	ray_pos;
	double	ray_angle;
	double	distance;
	double	x;
	double	y;
	double	dx;
	double	dy;
	
	ray_pos = 0.5;
	ray_angle = (double)FOV * ray_pos - (double)FOV / 2 + var->plr->p_angle;
	var->plr->radians = ray_angle * M_PI / 180;
	dx = cos(var->plr->radians);
	dy = sin(var->plr->radians);
	x = var->plr->pos_x;
	y = var->plr->pos_y;
	distance = 0;
	while(distance < 1000)
	{
		if (ft_is_wall(var,x,y))
			break;
		x += dx;
		y += dy;
		distance++;
	}
	var->plr->mid_ray = distance;
}

void	ft_cast_rayz(t_var *var)
{
	double	ray_pos;
	double	ray_angle;
	double	distance;
	double	x;
	double	y;
	double	dx;
	double	dy;
	int		x_ing;

	ray_pos = 0;
	x_ing = 0;
	ft_get_dist(var);
	while(ray_pos < 1.0 )
	{	
		if (x_ing >= SCREEN_WIDTH)
			x_ing = 0;
		ray_angle = (double)FOV * ray_pos - (double)FOV / 2 + var->plr->p_angle;
		var->plr->radians = ray_angle * M_PI / 180;
		dx = cos(var->plr->radians);
		dy = sin(var->plr->radians);
		x = var->plr->pos_x;
		y = var->plr->pos_y;
		distance = 0;
		while(distance < 1000)
		{
			if (ft_is_wall(var,x,y))
				break;
			x += dx;
			y += dy;
			distance += 1;
		}
		// distance = distance * cos(var->plr->radians);
		// printf("%f distance\n", distance);
		// printf("%f radians\n", var->plr->radians);
		ft_draw_wall(var, distance, x_ing);
		ray_pos += 0.00125;// decrease for more rays
		x_ing++;
	}
}

void	ft_draw_wall(t_var *var, int distance, int x_ing)
{
	double	p_plane_dist;
	double	p_wall_height;
	int		y;
	int		to_draw;
	// double	remainder_sq;
	// double	x;
	
	// x = tan((double)FOV / 2) * var->plr->mid_ray;
	p_plane_dist = (SCREEN_WIDTH / 2) / tan((double)FOV) / 2;
	p_wall_height = (double)var->map->modul_w / (double)distance * p_plane_dist;
	if (p_wall_height < 0)
		p_wall_height *= -1;
	y = (SCREEN_HEIGHT / 2) - (p_wall_height / 2);
	to_draw = 0;
	while(to_draw < SCREEN_HEIGHT)
	{
		if (to_draw <= y)
			img_pix_put(var, x_ing, to_draw, 0x0000FF);
		else if (to_draw >= y && to_draw <= p_wall_height + y)
			img_pix_put(var, x_ing, to_draw, 0xFFFFFF);
		else if (to_draw >= p_wall_height)
			img_pix_put(var, x_ing, to_draw, 0x800000);
		to_draw++;
	}

}