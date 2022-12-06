/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:18:44 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/06 11:34:48 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_map(t_map *map)
{
	map->color_c = NULL;
	map->color_f = NULL;
	map->data = NULL;
	map->tex_e = NULL;
	map->tex_n = NULL;
	map->tex_s = NULL;
	map->tex_w = NULL;
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->img = NULL;
	mlx->ptr = NULL;
	mlx->window = NULL;
}

void	init_struct(t_var *var)
{
	init_map(var->map);
	init_mlx(var->mlx);
	var->posx = -1;
	var->posy = -1;
}
