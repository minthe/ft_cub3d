/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytake.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:03:45 by dimbrea           #+#    #+#             */
/*   Updated: 2022/12/10 18:44:50 by dimbrea          ###   ########.fr       */
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
	render_background(var, 0xFFFFFF);
	// ft_player(var);
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

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
int	main(int argc, char **argv)
{
	t_var	var;
	t_mlx	data_m;
	t_img	s_img;
	t_player	player;
	char	*map[MAP_HEIGHT];

	map[0] = "11111111";
	map[1] = "11100001";
	map[2] = "10000001";
	map[3] = "11111111";
	map[4] = NULL;
	var.mlx = &data_m;
	var.img = &s_img;
	var.plr = &player;

	(void)map;
	(void)argv;
	var.plr->pos_x = 300;// need to get position of the player;
	var.plr->pos_y = 300;
	// var.img->width=10;
	// var.img->height=10;
	if (argc == 2)
	{
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