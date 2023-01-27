/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:47:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/27 19:23:14 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

double	degree_to_radians(double degree)
{
	return (degree * (double)M_PI / 180.0);
}

void	ft_get_dist(t_var *var, double dx, double dy, double ray_pos)
{
	double	ray_angle;
	double	distance;
	double	x;
	double	y;

	ray_pos = 0.5;
	ray_angle = (double)FOV * ray_pos - (double)FOV / 2 + var->plr->p_angle;
	var->plr->radians = ray_angle * (double)M_PI / 180.0;
	dx = cos(var->plr->radians);
	dy = sin(var->plr->radians);
	x = var->plr->pos_x;
	y = var->plr->pos_y;
	distance = 0;
	while (distance < 1000)
	{
		if (ft_is_wall(var, x, y))
		{
			ft_get_wall_orient(var, x, y);
			break ;
		}
		x += dx;
		y += dy;
		distance += 1 ;
	}
	var->plr->mid_ray = distance;
}

static void	ft_cast_rayz2(t_var *var)
{
	double	distance;

	distance = 0;
	while (distance < 10000)
	{
		if (ft_is_wall(var, var->txt->ray_x, var->txt->ray_y))
		{
			ft_get_wall_orient(var, var->txt->ray_x, var->txt->ray_y);
			break ;
		}
		var->txt->ray_x += var->txt->ray_dx;
		var->txt->ray_y += var->txt->ray_dy;
		distance += 1;
	}
	distance *= cos((var->txt->ray_angle - var->plr->p_angle) * M_PI / 180.0);
	ft_draw_wall(var, distance);
}

void	ft_cast_rayz(t_var *var)
{
	var->txt->ray_pos = 0.0;
	var->txt->ray_x_ing = 0;
	ft_get_dist(var, 0.0, 0.0, 0.0);
	while (var->txt->ray_pos < 1.0)
	{
		if (var->txt->ray_x_ing >= SCREEN_WIDTH)
			var->txt->ray_x_ing = 0;
		var->txt->ray_angle = (double)FOV * var->txt->ray_pos - \
		(double)FOV / 2 + var->plr->p_angle;
		var->plr->radians = var->txt->ray_angle * (double)M_PI / 180.0;
		var->txt->ray_dx = cos(var->plr->radians);
		var->txt->ray_dy = sin(var->plr->radians);
		var->txt->ray_x = var->plr->pos_x;
		var->txt->ray_y = var->plr->pos_y;
		ft_cast_rayz2(var);
		var->txt->ray_pos += 0.00125;
		var->txt->ray_x_ing++;
	}
}
