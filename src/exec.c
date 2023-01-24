/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:33:53 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/24 16:57:16 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	keypress(int key, t_var *var)
{
	if (key == ESC)
		x_window(var);
	if (key == W)
		ft_w(var);
	if (key == A)
		ft_a(var);
	if (key == S)
		ft_s(var);
	if (key == D)
		ft_d(var);
	if (key == M)
		ft_m(var);
	if (key == L_ARROW || key == R_ARROW)
		ft_lr_arrows(var, key);
	return (0);
}

int	render(t_var *var)
{
	if (var->mlx->window == NULL)
		return (1);
	ft_cast_rayz(var);
	if (var->map->minimap)
		ft_set_walls(var);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, \
							var->img->structure, 0, 0);
	return (0);
}

void	ft_player(t_var *var)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = var->plr->mini_x ;
	y = var->plr->mini_y;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
		{
			img_pix_put(var, x, y, 0xFF0000);
			x += 1;
		}
		x = var->plr->mini_x + 1;
		y += 1;
	}
}

void	ft_map_size(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	var->map->map_h = 0;
	var->map->map_w = 0;
	var->map->minimap = 0;
	while (var->data->map[i])
	{
		j = 1;
		while (var->data->map[i][j])
			j++;
		if (j > var->map->map_w)
			var->map->map_w = j;
		i++;
	}
	var->map->map_h = i;
	var->map->modul_w = SCREEN_WIDTH / var->map->map_w;
	var->map->modul_h = SCREEN_HEIGHT / var->map->map_h;
}

void	ft_ray(t_var *var, char nswe)
{
	ft_textures(var);
	ft_starting_angle(var, nswe);
	ft_cast_rayz(var);
}
