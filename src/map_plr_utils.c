/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:18:21 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/26 15:30:09 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	ft_color(t_var *var, int height, int width)
{
	int	i;
	int	j;

	i = height;
	while (i < (height + var->map->modul_h / 3 + 1))
	{
		j = width;
		while (j < (width + var->map->modul_w / 4 + 1))
		{
			img_pix_put(var, j, i, 0x808080);
			j++;
		}
		i++;
	}
}

void	ft_set_walls(t_var *var)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	height = 0;
	while (var->data->map[++i])
	{
		j = -1;
		width = (SCREEN_WIDTH / 4) * 3;
		while (var->data->map[i][++j])
		{
			if (var->data->map[i][j] == '1')
				ft_color(var, height, width);
			width += var->map->modul_w / 4;
		}
		height += var->map->modul_h / 3;
	}
}

int	ft_is_wall(t_var *var, int x, int y)
{
	int	col;
	int	row;

	col = x / var->map->modul_w;
	row = y / var->map->modul_h;
	if (var->data->map[row][col] == '1')
		return (1);
	return (0);
}

void	ft_put_player(t_var *var)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	height = 0;
	while (var->data->map[++i])
	{
		j = -1;
		width = 0;
		while (var->data->map[i][++j])
		{
			if (ft_strchr("NSEW", var->data->map[i][j]))
			{
				var->plr->pos_x = width + var->map->modul_w / 4 / 2;
				var->plr->pos_y = height + var->map->modul_h / 3 / 2;
				var->plr->orient = var->data->map[i][j];
			}
			width += var->map->modul_w;
		}
		height += var->map->modul_h;
	}
}

void	ft_starting_angle(t_var *var, char nswe)
{
	var->plr->ray_pos = 0.0;
	var->plr->p_angle = 270.0;
	if (nswe == 'S')
		var->plr->p_angle = 90.0;
	if (nswe == 'W')
		var->plr->p_angle = 180;
	if (nswe == 'E')
		var->plr->p_angle = 0;
	var->plr->c_angle = var->plr->p_angle;
}
