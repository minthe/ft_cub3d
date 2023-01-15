/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:03:45 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/13 16:20:50 by dimbrea          ###   ########.fr       */
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
	ft_cast_rayz(var, var->plr->radians);
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
			if (var->map->d_map[i][j] == '1' || var->map->d_map[i][j] == ' ')
				ft_color(var, height, width);
			width += var->map->modul_w;
		}
		height += var->map->modul_h;
	}
}

// void ft_grid_dims(t_var *var)
// {
// 	int g_rows;
// 	int	g_cols;
// 	int	i;
// 	int	j;
// 	int	height;
// 	int width;

// 	g_rows = var->map->map_h;
// 	g_cols = var->map->map_w;
// 	var->map->grid_dims = malloc(sizeof(int *) * g_rows);
// 	i = 0;
// 	while (i < g_rows)
// 	{
// 		var->map->grid_dims[i] = malloc(sizeof(int) * g_cols * 2);
// 		i++;
// 	}
// 	height = 0;
// 	width = 0;
// 	i = 0;
// 	while (i < g_rows)
// 	{
// 		j = 0;
// 		while(j < g_cols)
// 		{
// 			var->map->grid_dims[i][j * 2] = height;
// 			printf("%d\n", var->map->grid_dims[i][j * 2]);
// 			var->map->grid_dims[i][j * 2 + 1] = width; 
// 			width += var->map->modul_w;
// 			j++;
// 		}
// 		height += var->map->modul_h;
// 		width = 0;
// 		i++;
// 	}
	
// }

int ft_is_in_wall(t_var *var, int height, int width, int x, int y)
{
	if (x >= width && x < width + var->map->modul_w &&
	y >= height && y < height + var->map->modul_h)
		return (1);
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
			if (var->map->d_map[i][j] == '1' &&
			ft_is_in_wall(var, height, width, x, y))
				return (1);
			width += var->map->modul_w;
		}
		height += var->map->modul_h;
	}
	return (0);
}

// int	ft_is_wall(t_var *var, int x, int y)
// {
// 	int	i;
// 	int	j;
// 	int	width;
// 	int	height;

// 	i = -1;
// 	(void)x;
// 	(void)y;
// 	// height = 0;
// 	while (++i < var->map->map_h)
// 	{
// 		j = -1;
// 		while (++j < var->map->map_w)
// 		{
// 			height = var->map->grid_dims[i][j * 2];
// 			width = var->map->grid_dims[i][j * 2 + 1];
// 			printf("%d height\n", height);
// 			printf("%d width\n", width);
// 			if (var->map->d_map[i][j] == '1' && ft_is_in_wall(var,height,width, x, y))
// 				return (1);
// 		}
// 	}
// 	return (0);
// }

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
			if (ft_strchr("NSEW", var->map->d_map[i][j]))
			{
				var->plr->pos_x = width + var->map->modul_w / 2;
				var->plr->pos_y = height + var->map->modul_h / 2;
				var->plr->orient = var->map->d_map[i][j];
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

// void	ft_plr_orient(t_var *var, char nswe)
// {
// 	if (nswe == 'N')
// 	{
// 		var->plr->end_y = var->plr->pos_y - 25;
// 		var->plr->end_x = var->plr->pos_x;
// 	}
// 	if (nswe == 'S')
// 	{
// 		var->plr->end_y = var->plr->pos_y + 25;
// 		var->plr->end_x = var->plr->pos_x;
// 	}
// 	if (nswe == 'W')
// 	{
// 		var->plr->end_y = var->plr->pos_y;
// 		var->plr->end_x = var->plr->pos_x - 25;
// 	}
// 	if (nswe == 'E')
// 	{
// 		var->plr->end_y = var->plr->pos_y;
// 		var->plr->end_x = var->plr->pos_x + 25;
// 	}
// }

void	ft_ray(t_var *var, char nswe)
{
	
	ft_starting_angle(var, nswe);
	ft_cast_rayz(var, var->plr->radians);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->structure, 0, 0);

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
	var.map->d_map[0] = "1111111111111111111111111";
	var.map->d_map[1] = "10S00000001100000000001";
	var.map->d_map[2] = "100000000111000000011111";
	var.map->d_map[3] = "1001000000000000000000011";
	var.map->d_map[4] = "1111111110110000011110001";
	var.map->d_map[5] = "1111111111111111111111111";
	var.map->d_map[6] = NULL;
	(void)argv;
	if (argc == 2)
	{
		ft_map_size(&var);
		// ft_grid_dims(&var);
		ft_put_player(&var);
		var.mlx->ptr = mlx_init();
		var.mlx->window = mlx_new_window(var.mlx->ptr,SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
		var.img->structure = mlx_new_image(var.mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
		var.img->addr = mlx_get_data_addr(var.img->structure, &var.img->bpp, &var.img->size_line, &var.img->endian);
		ft_ray(&var, var.plr->orient);
		mlx_loop_hook(var.mlx->ptr, &render, &var);
		mlx_hook(var.mlx->window, 17, 0L, x_window, &var);
		mlx_hook(var.mlx->window,2, (1l << 0),keypress, &var);
		mlx_loop(var.mlx->ptr);
	}
	else
		write(2, "Error 2 arguments needed\n", 25);
	return (0);
}