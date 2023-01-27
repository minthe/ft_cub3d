/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:37:36 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/27 22:51:58 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

double	degree_to_radians(double degree)
{
	return (degree * (double)M_PI / 180.0);
}

static void	ft_cast_rayz2(t_var *var)
{
	var->txt->ray_distance = 0;
	while (var->txt->ray_distance < 10000)
	{
		if (ft_is_wall(var, var->txt->ray_x, var->txt->ray_y))
		{
			ft_get_wall_orient(var, var->txt->ray_x, var->txt->ray_y);
			break ;
		}
		var->txt->ray_x += var->txt->ray_dx;
		var->txt->ray_y += var->txt->ray_dy;
		var->txt->ray_distance += 1;
	}
}

void	ft_cast_rayz(t_var *var)
{
	var->txt->ray_pos = 0.0;
	var->txt->ray_x_ing = 0;
	ft_get_dist(var);
	while (var->txt->ray_pos < 1.0)
	{
		if (var->txt->ray_x_ing >= SCREEN_WIDTH)
			var->txt->ray_x_ing = 0;
		var->txt->ray_angle = (double)FOV * var->txt->ray_pos \
			-(double)FOV / 2 + var->plr->p_angle;
		var->plr->radians = var->txt->ray_angle * (double)M_PI / 180.0;
		var->txt->ray_dx = cos(var->plr->radians);
		var->txt->ray_dy = sin(var->plr->radians);
		var->txt->ray_x = var->plr->pos_x;
		var->txt->ray_y = var->plr->pos_y;
		ft_cast_rayz2(var);
		var->txt->ray_distance *= cos((var->txt->ray_angle \
			- var->plr->p_angle) * M_PI / 180.0);
		ft_draw_wall(var, var->txt->ray_distance, \
			var->txt->ray_x_ing, var->txt->ray_x);
		var->txt->ray_pos += 0.00125;
		var->txt->ray_x_ing++;
	}
}
