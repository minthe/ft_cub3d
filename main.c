/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:03:45 by dimbrea           #+#    #+#             */
/*   Updated: 2022/12/12 19:26:35 by dimbrea          ###   ########.fr       */
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
	return 0;
}
int	render(t_var *var)
{
	if (var->mlx->window == NULL)
		return (1);
	ft_set_walls(var);
	render_background(var);
	ft_player(var);
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
	x = var->plr->pos_x;
	y = var->plr->pos_y;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
		{
			img_pix_put(var, var->plr->pos_x, var->plr->pos_y,0xFF0000);
			var->plr->pos_x += 1;
		}
		var->plr->pos_x = x;
		var->plr->pos_y += 1;
	}
	var->plr->pos_x = x;
	var->plr->pos_y = y;
}

void	ft_map_size(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	var->map->map_h = 0;
	var->map->map_w = 0;
	while (var->map->d_map[i])
	{
		j = 1;
		while(var->map->d_map[i][j])
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
	while (var->map->d_map[++i])
	{
		j = -1;
		width = 0;
		while (var->map->d_map[i][++j])
		{
			if (var->map->d_map[i][j] == '1')
				ft_color(var, height, width);
			width += var->map->modul_w;
		}
		height += var->map->modul_h;
	}
}

int ft_is_in_wall(t_var *var, int height, int width, int x, int y)
{
	int i;
	int j;

	i = height;
	while (i < (height + var->map->modul_h + 1))
	{
		j = width;
		while(j < (width + var->map->modul_w + 1))
		{
			if (i == y && j == x )
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_wall(t_var *var, int x, int y)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	height = 0;
	while (var->map->d_map[++i])
	{
		j = -1;
		width = 0;
		while (var->map->d_map[i][++j])
		{
			if (var->map->d_map[i][j] == '1')
				if (ft_is_in_wall(var, height, width, x, y) == 1)
					return (1);
			width += var->map->modul_w;
		}
		height += var->map->modul_h;
	}
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
	while (var->map->d_map[++i])
	{
		j = -1;
		width = 0;
		while (var->map->d_map[i][++j])
		{
			if (ft_strchr("NSEW", var->map->d_map[i][j]) != NULL)
			{
				var->plr->pos_x = width + var->map->modul_w / 2;
				var->plr->pos_y = height + var->map->modul_h / 2;
			}
			width += var->map->modul_w;
		}
		height += var->map->modul_h;
	}
}

int	main(int argc, char **argv)
{
	t_var	var;
	t_map	map_m;
	t_mlx	data_m;
	t_img	s_img;
	t_player	player;
	var.mlx = &data_m;
	var.map = &map_m;
	var.img = &s_img;
	var.plr = &player;
	var.map->d_map[0] = "        1111111111111111111111111";
	var.map->d_map[1] = "        1000000000110000000000001";
	var.map->d_map[2] = "        1011000001110000000000001";
	var.map->d_map[3] = "        1001000000000000000E00001";
	var.map->d_map[4] = "111111111011000001110000000000001";
	var.map->d_map[5] = "100000000011000001110111111111111";
	var.map->d_map[6] = "11110111111111011100000010001";
	var.map->d_map[7] = "11110111111111011101010010001";
	var.map->d_map[8] = "11000000110101011100000010001";
	var.map->d_map[9] = "10000000000000001100000010001";
	var.map->d_map[10] = "10000000000000001101010010001";
	var.map->d_map[11] = "110000011101010111110111100111";
	var.map->d_map[12] = "11110111 1110101 101111010001";
	var.map->d_map[13] = "11111111 1111111 111111111111";
	var.map->d_map[14] = NULL;
	(void)argv;
	if (argc == 2)
	{
		ft_map_size(&var);
		ft_put_player(&var);
		var.mlx->ptr = mlx_init();
		var.mlx->window = mlx_new_window(var.mlx->ptr,SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
		var.img->structure = mlx_new_image(var.mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
		var.img->addr = mlx_get_data_addr(var.img->structure, &var.img->bpp, &var.img->size_line, &var.img->endian);
		mlx_loop_hook(var.mlx->ptr, &render, &var);
		mlx_hook(var.mlx->window, 17, 0L, x_window, &var);
		mlx_hook(var.mlx->window,2, (1l << 0),keypress, &var);
		mlx_loop(var.mlx->ptr);
	}
	else
		write(2, "Error 2 arguments needed\n", 25);
	return (0);
}