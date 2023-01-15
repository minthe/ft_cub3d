/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/13 16:22:53 by dimbrea          ###   ########.fr       */
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

void	ft_cast_rayz(t_var *var, double radians)
{
	double	ray_pos;
	double	ray_angle;
	int		distance;
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	fov;

	(void)radians;
	fov = FOV;
	ray_pos = 0.0;
	while(ray_pos < 1.0 )
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
			if (ft_is_wall(var,x,y))
				break;
			x += dx;
			y += dy;
			distance += 5;
		}
		ray_pos += 0.005;// decrease for more rays
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
// 				// int walz = 0;
// 				var->map->wall_sx = ((var->plr->pos_x + distance * cos(var->plr->radians)) - (SCREEN_WIDTH / 2)) * -1;
// 				var->map->wall_ex = (var->plr->pos_x + distance * cos(var->plr->radians)) + (SCREEN_WIDTH / 2);
// 				var->map->wall_sy = ((var->plr->pos_y + distance * sin(var->plr->radians)) - (SCREEN_HEIGHT / 2)) * -1;
// 				var->map->wall_ey = (var->plr->pos_y + distance * sin(var->plr->radians)) + (SCREEN_HEIGHT / 2);
// 				printf("%d wall_start_x\n", var->map->wall_sx);
// 				printf("%d wall_end_x\n", var->map->wall_ex);
// 				printf("%d wall_start_y\n", var->map->wall_sy);
// 				printf("%d wall_end_y\n", var->map->wall_ey);
				
// 				// var->map->wall_height = SCREEN_HEIGHT / distance;
// 				// draw_ln(var);
// 				// while(walz < SCREEN_WIDTH)
// 				// {
// 					img_pix_put(var, var->map->wall_ex, var->map->wall_ey, 0xFFFFFF);
// 					img_pix_put(var, var->map->wall_sx, var->map->wall_sy, 0xFFFFFF);
// 					// img_pix_put(var, x, y, 0xFFFFFF);
// 					// img_pix_put(var, x, y, 0xFFFFFF);
// 					// walz++;
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

// void ft_draw wall
// void ft_cast_rayz(t_var *var, double radians)
// {
// 	double ray_pos = 0.0;
// 	double ray_angle;
// 	double distance;
// 	double x;
// 	double y;
// 	double dx;
// 	double dy;
// 	double fov;	
// 	(void)radians;
// 	fov = FOV;
// 	while (ray_pos <= 1.0)
// 	{
// 		ray_angle = fov * ray_pos - fov / 2 + var->plr->p_angle;
// 		var->plr->radians = ray_angle * M_PI / 180;
// 		dx = cos(var->plr->radians);
// 		dy = sin(var->plr->radians);
// 		x = var->plr->pos_x;
// 		y = var->plr->pos_y;
// 		distance = 0;
// 		while (distance < 10000) 
// 		{
// 			if (ft_is_wall(var, x, y) > 0)
// 			{
// 				var->map->wall_sx = (var->plr->pos_x + distance * cos(var->plr->radians));
// 				var->map->wall_ex = (var->plr->pos_x + distance * cos(var->plr->radians)) + (SCREEN_WIDTH / 2);
// 				var->map->wall_sy = (var->plr->pos_y + distance * sin(var->plr->radians));
// 				var->map->wall_ey = (var->plr->pos_y + distance * sin(var->plr->radians)) + (SCREEN_HEIGHT / 2);	
// 				//Calculate wall height
// 				var->map->wall_height = SCREEN_HEIGHT / distance;
// 				while(var->map->wall_sx < var->map->wall_ex + 1)
// 				{
// 					int yyy = var->map->wall_sy;
// 					while(yyy < var->map->wall_ey + 1)
// 					{
// 						img_pix_put(var, var->map->wall_sx, yyy, 0xFFFFFF);
// 						yyy++;
// 					}
// 					var->map->wall_sx++;
// 				}
// 				// printf("%d wall_start_x\n", var->map->wall_sx);
// 				// printf("%d wall_end_x\n", var->map->wall_ex);
// 				// printf("%d wall_start_y\n", var->map->wall_sy);
// 				// printf("%d wall_end_y\n", var->map->wall_ey);
// 				// ft_draw_wall(var, var->map->wall_sx, var->map->wall_ex, var->map->wall_sy, var->map->wall_ey, var->map->wall_height);
// 				break;
// 			}
// 				x += dx;
// 				y += dy;
// 				distance += 1;
// 		}
// 		ray_pos += 0.1;
// 	}
// }

// void ft_cast_rayz(t_var *var, double radians)
// {
// 	double ray_pos;
// 	double ray_angle;
// 	double distance;
// 	double x;
// 	double y;
// 	double dx;
// 	double dy;
// 	double fov;
// 	// double wall_height;
// 	double wall_x;
// 	double wall_top;
// 	double wall_bottom;
// 	double wall_length;
// 	// double camera_x
// 	(void)radians;
// 	fov = 60;
// 	ray_pos = 0.0;
// 	while (ray_pos <= 1.0)
// 	{
// 		//Calculate the angle of the current ray
// 		ray_angle = fov * ray_pos - (fov / 2) + var->plr->p_angle;
// 		var->plr->radians = ray_angle * M_PI / 180;
// 		dx = cos(var->plr->radians);
// 		dy = sin(var->plr->radians);
// 		x = var->plr->pos_x;
// 		y = var->plr->pos_y;
// 		distance = 0;
// 		while (distance < 10000)
// 		{
// 			if (ft_is_wall(var, x, y) > 0)
// 			{
// 				wall_length = SCREEN_HEIGHT / distance;
// 				wall_x = (x - var->plr->pos_x) / (y - var->plr->pos_y);
// 				wall_x = (wall_x * SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 2);
// 				wall_top = (SCREEN_HEIGHT - wall_length) / 2;
// 				wall_bottom = wall_top + wall_length;
// 				while (wall_top < wall_bottom)
// 				{
// 					img_pix_put(var, wall_x, wall_top, 0xFFFFFF);
// 					wall_top++;
// 				}
// 				break;
// 			}
// 			x += dx;
// 			y += dy;
// 			distance += 1;
// 		}
// 		ray_pos += 0.01;
// 	}
// }
