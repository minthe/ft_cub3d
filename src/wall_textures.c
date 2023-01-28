/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:54:25 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/28 13:42:51 by dimbrea          ###   ########.fr       */
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

static void	ft_draw_wall2(t_var *var, int x_ing, int coo_x, int y)
{
	int		ty;
	int		color;

	ty = y;
	if (var->map->is_w_or_e == 0)
		ty = (double)(var->wall_td - var->wall_txt_y) / (var->wall_ph) \
			* (double)TXT_W;
	if (var->map->is_w_or_e == 1 || var->map->is_w_or_e == 2)
		coo_x = (double)(var->wall_td - var->wall_txt_y) / (var->wall_ph) \
			* (double)TXT_W;
	color = ft_texturing(var, coo_x, ty, 0.0);
	img_pix_put(var, x_ing, var->wall_td, color);
}

void	ft_draw_wall(t_var *var, int distance, int x_ing, int coo_x)
{
	var->wall_ph = 32.0 / distance * (SCREEN_WIDTH / 2) / tan((double)FOV) / 2;
	var->wall_txt_y = (SCREEN_HEIGHT / 2) - (var->wall_ph / 2);
	var->wall_td = 0;
	while (var->wall_td < SCREEN_HEIGHT)
	{
		if (var->wall_td < var->wall_txt_y)
			img_pix_put(var, x_ing, var->wall_td, var->data->c);
		else if (var->wall_td >= var->wall_txt_y && var->wall_td <= \
			(int)(var->wall_ph + var->wall_txt_y))
			ft_draw_wall2(var, x_ing, coo_x, var->txt->ray_y);
		else if (var->wall_td > var->wall_ph)
			img_pix_put(var, x_ing, var->wall_td, var->data->f);
		var->wall_td++;
	}
}
