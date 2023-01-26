/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:54:25 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/26 16:56:05 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	ft_texturing(t_var *var, int x, int y)
{
	int		diff;
	int		start;
	double	percent;

	start = x;
	diff = start % var->map->modul_w;
	// printf("%d x \n", diff);
	if (var->map->is_w_or_e == 1)
	{
		y = (int)y % var->map->modul_h;
		y = (y / var->map->modul_h) * var->map->modul_h;
	}
	percent = ((double)diff / (double)var->map->modul_w) * (double)TXT_W;
	return (ft_get_pxl_color(var, percent, y));
}

void	ft_draw_wall(t_var *var, int distance, int x_ing, int coo_x)
{
	double	p_wall_height;
	int		y;
	int		to_draw;
	int		color;
	int		texture_y;

	p_wall_height = 32.0 / distance * (SCREEN_WIDTH / 2) 
						/ tan((double)FOV) / 2;
	y = (SCREEN_HEIGHT / 2) - (p_wall_height / 2);
	to_draw = 0;
	var->plr->real_wall_height = y;
	while (to_draw < SCREEN_HEIGHT)
	{
		if (to_draw < y)
			img_pix_put(var, x_ing, to_draw, var->data->c);
		else if (to_draw >= y && to_draw <= (int)(p_wall_height + y))
		{
			texture_y = (double)(to_draw - y) / (p_wall_height) \
						* (double)TXT_W;
			if (var->map->is_w_or_e == 1)
				coo_x ++;
			else if (var->map->is_w_or_e == 2)
				coo_x --;
			color = ft_texturing(var, coo_x, texture_y);
			img_pix_put(var, x_ing, to_draw, color);
		}
		else if (to_draw > p_wall_height)
			img_pix_put(var, x_ing, to_draw, var->data->f);
		to_draw++;
	}
}	
