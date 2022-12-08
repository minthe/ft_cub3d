/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytake.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:03:45 by dimbrea           #+#    #+#             */
/*   Updated: 2022/12/08 14:51:42 by dimbrea          ###   ########.fr       */
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

// int	render(t_var *var)
// {
// 	// if (var->mlx->ptr == NULL)
// 	// 	return (1);
// 	// mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->img_xpm, var->plr->pos_x, var->plr->pos_y);
// 	return (0);
// }

void	start(t_mlx *mlx)
{
	(void)mlx;
	// mlx_hook(var->mlx->window, 17, 0L, x_window, var->mlx);
	// mlx_new_image(var->mlx->ptr, var->posx, var->posy);
	
}

int	main(int argc, char **argv)
{
	t_var	var;
	t_mlx	data_m;
	t_img	s_img;
	t_player	player;
	char	*map[MAP_HEIGTH];

	map[0] = "11111111";
	map[1] = "10000001";
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
	if (argc == 2)
	{
		var.mlx->ptr = mlx_init();
		var.mlx->window = mlx_new_window(var.mlx->ptr,SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
		var.img->img_ptr = mlx_new_image(var.mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
		var.img->addr = mlx_get_data_addr(var.img->img_ptr, &var.img->bpp, &var.img->line_len, &var.img->endian);
		mlx_hook(var.mlx->window, 17, 0L, x_window, &var);
		mlx_hook(var.mlx->window,2, (1l << 0),keypress, &var);
		mlx_pixel_put(var.mlx->ptr, var.mlx->window, var.plr->pos_x, var.plr->pos_y, 0xFF0000);
		// ft_pixl_put(&var, var.plr->pos_x, var.plr->pos_y, 0xFF0000);
		mlx_loop(var.mlx->ptr);
	}
	else
		write(2, "Error 2 arguments needed\n", 25);
	return (0);
}
