/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/25 14:38:52 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// void	ft_get_dist(t_var *var)
// {
// 	double	ray_pos;
// 	double	ray_angle;
// 	double	distance;
// 	double	x;
// 	double	y;
// 	double	dx;
// 	double	dy;

// 	ray_pos = 0.5;
// 	ray_angle = (double)FOV * ray_pos - (double)FOV / 2 + var->plr->p_angle;
// 	var->plr->radians = ray_angle * (double)M_PI / 180.0;
// 	dx = cos(var->plr->radians);
// 	dy = sin(var->plr->radians);
// 	x = var->plr->pos_x;
// 	y = var->plr->pos_y;
// 	distance = 0;
// 	while (distance < 1000)
// 	{
// 		if (ft_is_wall(var, x, y))
// 			break ;
// 		x += dx;
// 		y += dy;
// 		distance++;
// 	}
// 	var->plr->mid_ray = distance;
// }

void	ft_textures(t_var *var)
{
	int	width;
	int	height;

	var->txt->img_ptr = mlx_new_image(var->mlx->ptr, TXT_W, TXT_W);
	var->txt->img_ptr = mlx_xpm_file_to_image(var->mlx->ptr, var->data->no, \
						&width, &height);
	var->txt->tex_addr = mlx_get_data_addr(var->txt->img_ptr, \
						&var->txt->bpp_txt, &var->txt->sz_ln, \
						&var->txt->endian_txt);
}

int	ft_get_pxl_color(t_var *var, double x, double y)
{
	char	*dst;
	int		xx;
	int		yy;

	xx = x;
	yy = y;
	xx %= TXT_W;
	yy %= TXT_W;
	dst = var->txt->tex_addr + (yy * var->txt->sz_ln \
		+ xx * (var->txt->bpp_txt / 8));
	return (*(int *)dst);
}

double	degree_to_radians(double degree)
{
	return (degree * (double)M_PI / 180.0);
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

	ray_pos = 0.0;
	x_ing = 0;
	while (ray_pos < 1.0 )
	{
		if (x_ing >= SCREEN_WIDTH)
			x_ing = 0;
		ray_angle = (double)FOV * ray_pos - (double)FOV / 2 + var->plr->p_angle;
		var->plr->radians = ray_angle * (double)M_PI / 180.0;
		dx = cos(var->plr->radians);
		dy = sin(var->plr->radians);
		x = var->plr->pos_x;
		y = var->plr->pos_y;
		distance = 0;
		while (distance < 10000)
		{
			if (ft_is_wall(var, x, y))
				break ;
			x += dx;
			y += dy;
			distance += 1;
		}
		distance *= cos((ray_angle - var->plr->p_angle) * M_PI / 180.0);
		ft_draw_wall(var, distance, x_ing, x);
		ray_pos += 0.00125;// decrease for more rays
		x_ing++;
	}
}
