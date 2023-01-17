/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/17 16:58:47 by dimbrea          ###   ########.fr       */
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

void	ft_cast_rayz(t_var *var)
{
	double	ray_pos;
	double	ray_angle;
	double	distance;
	double	x;
	double	y;
	double	dx;
	double	dy;
	double		base_offset;
	double	p_wall_height;
	double	p_plane_dist;
	double squirt;
	// long double d_base_off;

	// double d_distance;
	
	// double	cam_len;
	int		x_ing;

	base_offset = 400.0 ;
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
		// printf("%f _rayangle\n", ray_angle);
		// printf("%f player_angle\n", var->plr->p_angle);
		// distance = distance * cos(var->plr->radians);
		// printf("%f base\n", base_offset);
		// ray_angle = ray_angle * M_PI / 180.0;
		// printf("%f distance before\n", distance);
		// if (distance < SCREEN_WIDTH / 2)
			// distance = SCREEN_WIDTH / 2;
		// d_distance = sqrt(pow(distance, 2.0) - pow(base_offset, 2.0));
		// printf("%f distance\n", d_distance);
		p_plane_dist = (SCREEN_WIDTH / 2) / tan((double)FOV) / 2;
		if (p_wall_height > SCREEN_HEIGHT)
		{
			p_wall_height = (double)var->map->modul_h * p_plane_dist / distance;	
		}
		else
		{
			distance *= distance;
			base_offset *= base_offset;
			// d_base_off = distance - base_offset;
			squirt = sqrt(distance);//something's off
			// printf("%Lf SQUIRT\n", d_base_off);
			p_wall_height = (double)var->map->modul_h * p_plane_dist / squirt;
		}
		ft_draw_wall(var, p_wall_height, x_ing);
		if (ray_pos >= 0.5)
			base_offset += 1.0;
		else
			base_offset -= 1.0;
		ray_pos += 0.00125;// decrease for more rays
		x_ing++;
	}
}

void	ft_draw_wall(t_var *var, double p_wall_height, int x_ing)
{
	
	int		y;
	int		to_draw;
	

	y = (SCREEN_HEIGHT / 2) - (p_wall_height / 2);
	to_draw = 0;
	while(to_draw < SCREEN_HEIGHT)
	{
		if (to_draw <= y)
			img_pix_put(var, x_ing, to_draw, var->data->c);
		else if (to_draw >= y && to_draw <= p_wall_height + y)
			img_pix_put(var, x_ing, to_draw, 0xFFFFFF);
		else if (to_draw >= p_wall_height)
			img_pix_put(var, x_ing, to_draw, var->data->f);
		to_draw++;
	}
}