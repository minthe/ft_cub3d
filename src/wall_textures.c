/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:54:25 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/27 19:30:50 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static int	ft_texturing(t_var *var, int x, int y, double percent)
{
	int		diff;
	int		y_diff;
	int		y_start;
	double	y_percent;
	int		start;

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
		y_diff = y_start % var->map->modul_h;
		y_percent = ((double)y_diff / (double)var->map->modul_h * \
			(double)TXT_W);
	}
	return (ft_get_pxl_color(var, percent, y_percent));
}

static void	ft_draw_wall2(t_var *var, double ph, int texture_y, int color)
{
	int		txt_y;

	txt_y = (SCREEN_HEIGHT / 2) - (ph / 2);
	var->plr->real_wall_height = txt_y;
	if (var->txt->to_draw < txt_y)
		img_pix_put(var, var->txt->ray_x_ing, var->txt->to_draw, var->data->c);
	else if (var->txt->to_draw >= txt_y && var->txt->to_draw <= \
		(int)(ph + txt_y))
	{
		texture_y = var->txt->ray_y;
		if (var->map->is_w_or_e == 0)
			texture_y = (double)(var->txt->to_draw - txt_y) \
				/ (ph) * (double)TXT_W;
		if (var->map->is_w_or_e == 1 || var->map->is_w_or_e == 2)
			var->txt->ray_x = (double)(var->txt->to_draw - txt_y) / (ph) \
						* (double)TXT_W;
		color = ft_texturing(var, var->txt->ray_x, texture_y, 0.0);
		img_pix_put(var, var->txt->ray_x_ing, var->txt->to_draw, color);
	}
	else if (var->txt->to_draw > ph)
		img_pix_put(var, var->txt->ray_x_ing, var->txt->to_draw, var->data->f);
}

void	ft_draw_wall(t_var *var, int distance)
{
	double	ph;

	ph = 32.0 / distance * (SCREEN_WIDTH / 2) / tan((double)FOV) / 2;
	while (var->txt->to_draw < SCREEN_HEIGHT)
	{
		ft_draw_wall2(var, ph, 0, 0);
		var->txt->to_draw++;
	}
}
