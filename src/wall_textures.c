/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:54:25 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/25 20:51:40 by dimbrea          ###   ########.fr       */
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
	percent = (double)diff / (double)var->map->modul_w;
	return (ft_get_pxl_color(var, percent * (double)TXT_W, y));
}

void	ft_draw_wall(t_var *var, int distance, int x_ing, int coo_x)
{
	double	p_wall_height;
	int		y;
	int		to_draw;
	int		color;
	int		texture_y;

	p_wall_height = 32.0 / distance * (SCREEN_WIDTH / 2) \
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
			color = ft_texturing(var, coo_x, texture_y);
			img_pix_put(var, x_ing, to_draw, color);
		}
		else if (to_draw > p_wall_height)
			img_pix_put(var, x_ing, to_draw, var->data->f);
		to_draw++;
	}
}
