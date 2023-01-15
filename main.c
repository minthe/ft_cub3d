/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:03:45 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/15 20:18:13 by dimbrea          ###   ########.fr       */
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
	if (key == L_ARROW || key == R_ARROW)
		ft_lr_arrows(var, key);
	return 0;
}
int	render(t_var *var)
{
	if (var->mlx->window == NULL)
		return (1);
	// ft_set_walls(var);
	// render_background(var);
	// ft_player(var);
	ft_cast_rayz(var);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->structure, 0, 0);
	return (0);
}

void ft_player(t_var *var)
{
	int i;
	int j;
	int x;
	int y;

	i = -1;
	x = var->plr->pos_x - 2;
	y = var->plr->pos_y - 2;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
		{
			img_pix_put(var, x, y,0xFF0000);
			x += 1;
		}
		x = var->plr->pos_x - 2;
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
	while (var->data->map[i])
	{
		j = 1;
		while(var->data->map[i][j])
			j++;
		if(j >  var->map->map_w)
			var->map->map_w = j;
		i++;
	}
	var->map->map_h = i;
	var->map->modul_w = SCREEN_WIDTH / var->map->map_w;
	var->map->modul_h = SCREEN_HEIGHT / var->map->map_h;
}

void ft_color(t_var *var, int height, int width)
{
	int i;
	int j;

	i = height;
	while (i < (height + var->map->modul_h + 1))
	{
		j = width;
		while(j < (width + var->map->modul_w + 1))
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
		width = 0;
		while (var->data->map[i][++j])
		{
			if (var->data->map[i][j] == '1' || var->data->map[i][j] == ' ')
				ft_color(var, height, width);
			width += var->map->modul_w;
		}
		height += var->map->modul_h;
	}
}

int	ft_is_wall(t_var *var, int x, int y)
{
	int col;
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
				var->plr->pos_x = width + var->map->modul_w / 2;
				var->plr->pos_y = height + var->map->modul_h / 2;
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
}

void	ft_ray(t_var *var, char nswe)
{
	
	ft_starting_angle(var, nswe);
	ft_cast_rayz(var);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->structure, 0, 0);

}

int	main(int argc, char **argv)
{
	t_var	var;
	t_map	map_m;
	t_mlx	data_m;
	t_img	s_img;
	t_player	player;
	t_data	cub_s;

	var.data = &cub_s;
	var.mlx = &data_m;
	var.map = &map_m;
	var.img = &s_img;
	var.plr = &player;
	if (argc == 2 && init_struct(&var) && import_cub(&var, argv[1], ".cub"))
	{
		ft_map_size(&var);
		ft_put_player(&var);
		var.mlx->ptr = mlx_init();
		var.mlx->window = mlx_new_window(var.mlx->ptr,SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
		var.img->structure = mlx_new_image(var.mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
		var.img->addr = mlx_get_data_addr(var.img->structure, &var.img->bpp, &var.img->size_line, &var.img->endian);
		ft_ray(&var, var.plr->orient);
		mlx_hook(var.mlx->window, 17, 0L, x_window, &var);
		mlx_hook(var.mlx->window,2, (1l << 0),keypress, &var);
		mlx_loop_hook(var.mlx->ptr, &render, &var);
		mlx_loop(var.mlx->ptr);
	}
	else
		error_msg_exit("Error only map needed as argument");
	cleanup(&var);
	return (0);
}