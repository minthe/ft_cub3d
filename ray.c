/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/18 16:28:36 by dimbrea          ###   ########.fr       */
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

void	ft_textures(t_var *var)
{
	int	width;
	int	height;
	var->txt->img_ptr = mlx_new_image(var->mlx->ptr, 64, 64); 
	var->txt->img_ptr = mlx_xpm_file_to_image(var->mlx->ptr, var->data->no, &width, &height);
	var->txt->tex_addr = mlx_get_data_addr(var->txt->img_ptr, &var->txt->bpp_txt, &var->txt->sz_ln, &var->txt->endian_txt);
}

int	ft_get_pxl_color(t_var *var, int y)
{
	char *dst;
	// double	wall_x;
	// int		texture_x;
	
	// texture_x
	// if (y > 64)
	// 	y %= 64;
	// if (y < 0)
	// 	y = 0;
	// printf("%d\n", y);
	dst = var->txt->tex_addr + (y * var->txt->sz_ln + 32 * (var->txt->bpp_txt / 8));
	return (*(int *)dst);
}


void	ft_cast_rayz(t_var *var)
{
	double	ray_pos;
	double	ray_angle;
	double	distance;
	// double	p_plane_dist;
	double	x;
	double	y;
	double	dx;
	double	dy;
	int		x_ing;
	// double	fov;

	// fov = FOV;
	ray_pos = 0.0;
	x_ing = 0;
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
		while(distance < 10000)
		{
			if (ft_is_wall(var,x,y))
				break;
			x += dx;
			y += dy;
			distance += 0.5;
		}
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
	int		color;

	(void)var;
	p_plane_dist = (SCREEN_WIDTH / 2) / tan((double)FOV) / 2;
	p_wall_height = 32.0 / distance * p_plane_dist;
	y = (SCREEN_HEIGHT / 2) - (p_wall_height / 2);
	to_draw = 0;
	// printf("%d y\n", y);
	// printf("%f wall_HEIGHT\n", p_wall_height);
	// printf("%d DISTANCE\n", distance);
	color = ft_get_pxl_color(var, 32);
	while(to_draw < SCREEN_HEIGHT)
	{
		if (to_draw < y)
			img_pix_put(var, x_ing, to_draw, 0x0000FF);
		else if (to_draw >= y && to_draw <= p_wall_height + y)
			img_pix_put(var, x_ing, to_draw, color);
		else if (to_draw > p_wall_height)
			img_pix_put(var, x_ing, to_draw, 0x800000);
		to_draw++;
	}
}
