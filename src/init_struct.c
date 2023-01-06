/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:18:44 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/06 17:37:02 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_cub(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = 0x00000000;
	data->c = 0x00000000;
	data->f_set = 0;
	data->c_set = 0;
	data->t = 0;
	data->r = 0;
	data->g = 0;
	data->b = 0;
	data->map = NULL;
	data->map_lst = ft_calloc(1, sizeof(t_linked_list));
	initialize_list(data->map_lst);
	data->err = 0;
	data->err_map = 0;
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->img = NULL;
	mlx->ptr = NULL;
	mlx->window = NULL;
}

int	init_struct(t_var *var)
{
	var->fd1 = 0;
	var->line = NULL;
	init_cub(var->data);
	init_mlx(var->mlx);
	var->posx = -1;
	var->posy = -1;
	return (1);
}
