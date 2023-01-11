/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/11 17:30:10 by dimbrea          ###   ########.fr       */
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
	double ray_pos;
	double ray_angle;
	double	distance;
	double x;
	double y;
	double dx;
	double dy;
	double fov;

	(void)radians;
	fov = FOV;
	ray_pos = 0.0;
	while(ray_pos < 1.0)
	{
		ray_angle = fov * ray_pos - fov / 2 + var->plr->p_angle;
		var->plr->radians = ray_angle * M_PI / 180;
		dx = cos(var->plr->radians);
		dy = sin(var->plr->radians);
		x = var->plr->pos_x;
		y = var->plr->pos_y;
		distance = 0;
		while(distance < 10000)
		{
			img_pix_put(var, x, y, 0xFFFFFE);
			if(ft_is_wall(var,x,y) > 0)
			{
				double walz = 0;
				var->map->wall_height = SCREEN_HEIGHT / (distance / 1.0);
				
				img_pix_put(var, x, y, 0xFFFFFF);
				while(walz < var->map->wall_height)
				{
					if (var->map->wall_height > 1)
					walz++;
				}
				break;
			}
			x += dx;
			y += dy;
			distance +=1;
		}
		
		ray_pos += 0.01;
	}
}
// void	ft_cast_rayz(t_var *var, double radians)
// {
// 	double ray_pos;
// 	double ray_angle;
// 	double	distance;
// 	// double	p_angl_radians;
// 	double x;
// 	double y;
// 	double dx;
// 	double dy;
// 	double fov;

// 	(void)radians;
// 	fov = FOV;
// 	while(ray_pos < 1.0)
// 	{
// 		ray_angle = fov * ray_pos - fov / 2 + var->plr->p_angle;
// 		var->plr->radians = ray_angle * M_PI / 180;
// 		dx = cos(var->plr->radians);
// 		dy = sin(var->plr->radians);
// 		x = var->plr->pos_x;
// 		y = var->plr->pos_y;
// 		distance = 0;
// 		while(distance < 10000)
// 		{
// 			if(ft_is_wall(var,x,y) > 0)
// 			{
// 				// double walz = 0;
// 				var->map->wall_sx = ((var->plr->pos_x + distance * cos(var->plr->radians)) * ray_pos - (SCREEN_WIDTH / 2));
// 				var->map->wall_ex = (var->plr->pos_x + distance * cos(var->plr->radians)) * ray_pos + (SCREEN_WIDTH / 2);
// 				var->map->wall_sy = ((var->plr->pos_y + distance * sin(var->plr->radians)) * ray_pos - (SCREEN_HEIGHT / 2));
// 				var->map->wall_ey = (var->plr->pos_y + distance * sin(var->plr->radians)) * ray_pos + (SCREEN_HEIGHT / 2);
// 				// printf("%d wall_sx\n", var->map->wall_sx);
// 				// printf("%d wall_ex\n", var->map->wall_ex);
// 				// printf("%d wall_sy\n", var->map->wall_sy);
// 				// printf("%d wall_ey\n", var->map->wall_ey);
				
// 				var->map->wall_height = SCREEN_HEIGHT / distance;
// 				draw_ln(var);
// 				// while(walz < var->map->wall_height)
// 				// {
// 					// img_pix_put(var, var->map->wall_sx, var->map->wall_sy, 0xFFFFFF);
// 					// img_pix_put(var, var->map->wall_ex, var->map->wall_ey, 0xFFFFFF);
// 					// img_pix_put(var, x, y, 0xFFFFFF);
// 					// img_pix_put(var, x, y, 0xFFFFFF);
// 				// 	if (var->map->wall_height > 1)
// 				// 	walz++;
// 				// }
// 				break;
// 			}
// 			x += dx;
// 			y += dy;
// 			distance += 1;
// 		}
		
// 		ray_pos += 0.05;
// 	}
// }