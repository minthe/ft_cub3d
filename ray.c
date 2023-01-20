/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/20 16:22:34 by dimbrea          ###   ########.fr       */
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
	var->txt->img_ptr = mlx_new_image(var->mlx->ptr, TXT_W, TXT_W); 
	var->txt->img_ptr = mlx_xpm_file_to_image(var->mlx->ptr, var->data->no, &width, &height);
	var->txt->tex_addr = mlx_get_data_addr(var->txt->img_ptr, &var->txt->bpp_txt, &var->txt->sz_ln, &var->txt->endian_txt);
}

int	ft_get_pxl_color(t_var *var, double x, double y)
{
	char	*dst;
	int		xx;
	
	xx = x;
	xx %= TXT_W ;
	if (y < 0)
		y *= -1;
	printf("%f x %f y\n", x, y);
	y *= (double)TXT_W;
	dst = var->txt->tex_addr + ((int)y * var->txt->sz_ln + xx  * (var->txt->bpp_txt / 8));
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
		ft_draw_wall(var, distance, x_ing, x);
		ray_pos += 0.00125;// decrease for more rays
		x_ing++;
	}
}

int	ft_texturing(t_var *var, int x, int y)
{
	int	diff;
	int	start;
	double percent;

	start = x;
	
	diff =  start % var->map->modul_w;
	percent = (double)diff / (double)var->map->modul_w;
	
	printf("%d x %d y %f r_W_h", x, y, var->plr->real_wall_height);
	var->plr->real_wall_height /= y;
	// if (diff == 0)
	// printf("%d x \n", start);
	// printf("%f percent \n", percent * (double)TXT_W);
	// 	return (ft_get_pxl_color(var, percent * TXT_W));
	// start = x - diff;
	return (ft_get_pxl_color(var, percent * (double)TXT_W, var->plr->real_wall_height));
}

void	ft_draw_wall(t_var *var, int distance, int x_ing, int coo_x)
{
	double	p_plane_dist;
	double	p_wall_height;
	int		y;
	int		to_draw;
	int		color;
	int		d_txt;

	(void)var;
	p_plane_dist = (SCREEN_WIDTH / 2) / tan((double)FOV) / 2;
	p_wall_height = 32.0 / distance * p_plane_dist;
	y = (SCREEN_HEIGHT / 2) - (p_wall_height / 2);
	to_draw = 0;
	d_txt = -1;
	var->plr->real_wall_height = y;
	while(to_draw < SCREEN_HEIGHT)
	{
		if (to_draw < y)
			img_pix_put(var, x_ing, to_draw, var->data->c);
		else if (to_draw >= y && to_draw <= (int)(p_wall_height + y))
		{
			color = ft_texturing(var, coo_x, ++d_txt);
			img_pix_put(var, x_ing, to_draw, color);
			
		}
		else if (to_draw > p_wall_height)
			img_pix_put(var, x_ing, to_draw, var->data->f);
		to_draw++;
	}
}