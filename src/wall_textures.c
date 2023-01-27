/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:54:25 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/27 16:58:41 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	ft_texturing(t_var *var, int x, int y)
{
	int		diff;
	int		y_diff;
	int		y_start;
	double	y_percent;
	int		start;
	double	percent;

	start = x;
	percent = start;
	y_start = y;
	if (var->map->is_w_or_e == 0)
	{
		diff = start % var->map->modul_w;
		percent = ((double)diff / (double)var->map->modul_w) * (double)TXT_W;
	}
	y_percent = y_start;
	if (var->map->is_w_or_e == 1 || var->map->is_w_or_e == 2)
	{
		y_diff = y_start %var->map->modul_h;
		y_percent = ((double)y_diff / (double)var->map->modul_h * (double)TXT_W);
	}
	return (ft_get_pxl_color(var, percent, y_percent));
}

void	ft_draw_wall(t_var *var, int distance, int x_ing, int coo_x, int y)
{
	double	p_wall_height;
	int		txt_y;
	int		to_draw;
	int		color;
	int		texture_y;

	p_wall_height = 32.0 / distance * (SCREEN_WIDTH / 2) 
						/ tan((double)FOV) / 2;
	txt_y = (SCREEN_HEIGHT / 2) - (p_wall_height / 2);
	to_draw = 0;
	var->plr->real_wall_height = txt_y;
	while (to_draw < SCREEN_HEIGHT)
	{
		if (to_draw < txt_y)
			img_pix_put(var, x_ing, to_draw, var->data->c);
		else if (to_draw >= txt_y && to_draw <= (int)(p_wall_height + txt_y))
		{
			texture_y = y;
			if (var->map->is_w_or_e == 0)
				texture_y = (double)(to_draw - txt_y) / (p_wall_height) \
						* (double)TXT_W;
			if (var->map->is_w_or_e == 1 || var->map->is_w_or_e == 2)
				coo_x = (double)(to_draw - txt_y) / (p_wall_height) \
							* (double)TXT_W;
			color = ft_texturing(var, coo_x, texture_y);
			img_pix_put(var, x_ing, to_draw, color);
		}
		else if (to_draw > p_wall_height)
			img_pix_put(var, x_ing, to_draw, var->data->f);
		to_draw++;
	}
}	
