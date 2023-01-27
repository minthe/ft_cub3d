/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/27 22:40:54 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	ft_get_dist(t_var *var)
{
	var->txt->dist_pos = 0.5;
	var->txt->dist_angle = (double)FOV * var->txt->dist_pos \
		- (double)FOV / 2 + var->plr->p_angle;
	var->plr->radians = var->txt->dist_angle * (double)M_PI / 180.0;
	var->txt->dist_dx = cos(var->plr->radians);
	var->txt->dist_dy = sin(var->plr->radians);
	var->txt->dist_x = var->plr->pos_x;
	var->txt->dist_y = var->plr->pos_y;
	var->txt->dist_distance = 0;
	while (var->txt->dist_distance < 1000)
	{
		if (ft_is_wall(var, var->txt->dist_x, var->txt->dist_y))
		{
			ft_get_wall_orient(var, var->txt->dist_x, var->txt->dist_y);
			break ;
		}
		var->txt->dist_x += var->txt->dist_dx;
		var->txt->dist_y += var->txt->dist_dy;
		var->txt->dist_distance += 1;
	}
}

void	ft_textures(t_var *var)
{
	int	width;
	int	height;

	var->txt->img_ptr = mlx_new_image(var->mlx->ptr, TXT_W, TXT_W);
	var->txt->texture_no = mlx_xpm_file_to_image(var->mlx->ptr, var->data->no, \
		&width, &height);
	var->txt->texture_so = mlx_xpm_file_to_image(var->mlx->ptr, var->data->so, \
		&width, &height);
	var->txt->texture_ea = mlx_xpm_file_to_image(var->mlx->ptr, var->data->ea, \
		&width, &height);
	var->txt->texture_we = mlx_xpm_file_to_image(var->mlx->ptr, var->data->we, \
		&width, &height);
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

static void	ft_get_wall_orient2(t_var *var, double x, double y)
{
	if ((int)y % var->map->modul_h == 0 && ((int)x % var->map->modul_w \
		!= var->map->modul_w - 1) && (var->plr->p_angle < 140.0 || \
		var->plr->p_angle > 60.0) \
		&& ((int)x % var->map->modul_w != 0))
		var->txt->tex_addr = mlx_get_data_addr(var->txt->texture_so, \
			&var->txt->bpp_txt, &var->txt->sz_ln, &var->txt->endian_txt);
	else if (((int)x % var->map->modul_w == var->map->modul_w - 1) && (int)y \
		% var->map->modul_h != 0 && (int)y % (var->map->modul_h) \
		!= var->map->modul_h - 1)
	{
		var->map->is_w_or_e = 2;
		var->txt->tex_addr = mlx_get_data_addr(var->txt->texture_we, \
			&var->txt->bpp_txt, &var->txt->sz_ln, &var->txt->endian_txt);
	}
}

void	ft_get_wall_orient(t_var *var, double x, double y)
{
	var->map->is_w_or_e = 0;
	if (((int)x % var->map->modul_w == 0) && (int)y % (var->map->modul_h) \
	!= var->map->modul_h - 1 && (int)y % var->map->modul_h != 0)
	{
		var->map->is_w_or_e = 1;
		var->txt->tex_addr = mlx_get_data_addr(var->txt->texture_ea, \
			&var->txt->bpp_txt, &var->txt->sz_ln, &var->txt->endian_txt);
	}	
	else if ((int)y % (var->map->modul_h) == var->map->modul_h - 1 && \
		(var->plr->p_angle > 140.0 || var->plr->p_angle < 60.0) && ((int)x % \
		var->map->modul_w != var->map->modul_w - 1))
		var->txt->tex_addr = mlx_get_data_addr(var->txt->texture_no, \
			&var->txt->bpp_txt, &var->txt->sz_ln, &var->txt->endian_txt);
	ft_get_wall_orient2(var, x, y);
}
