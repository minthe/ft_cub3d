/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:02 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/06 16:21:35 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// int	keypress(int key, t_var *var)
// {
// 	if (key == ESC)
// 		x_window(var->mlx);
// 	if (key == W)
// 		ft_w(var);
// 	if (key == A)
// 		var->posx -= 5;
// 	if (key == S)
// 		var->posy -= 5;
// 	if (key == D)
// 		var->posy += 5;
// 	return 0;
// }

// int	render(t_var *var)
// {
// 	// if (var->mlx->ptr == NULL)
// 	// 	return (1);
// 	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->mlx->img->img_xpm, var->posx, var->posy);
// 	// mlx_pixl_put(var, posx, var->posy, var->color);
	
// 	return (0);
// }

// void	start(t_mlx *mlx)
// {
// 	(void)mlx;
// 	// mlx_hook(var->mlx->window, 17, 0L, x_window, var->mlx);
// 	// mlx_new_image(var->mlx->ptr, var->posx, var->posy);
	
// }

// int	main(int argc, char **argv)
// {
// 	t_var	var;
// 	t_mlx	data_m;
// 	t_img	s_img;
	
// 	char 	*turd;

// 	turd = "turd.xpm";
// 	var.mlx = &data_m;
// 	var.mlx->img = &s_img;
// 	(void)argv;
// 	var.posx = 300;// need to get position of the player;
// 	var.posy = 300;
// 	if (argc == 2)
// 	{
// 		var.mlx->ptr = mlx_init();
// 		var.mlx->window = mlx_new_window(var.mlx->ptr, S_WIDTH, S_HEIGTH, "cub3d");
// 		var.mlx->img->img_xpm = mlx_xpm_file_to_image(var.mlx->ptr, turd, &var.mlx->img->width, &var.mlx->img->height);
// 		mlx_put_image_to_window(var.mlx->ptr, var.mlx->window, var.mlx->img->img_xpm, var.posx, var.posy);
// 		s_img.img_ptr = mlx_new_image(var.mlx->ptr, S_WIDTH, S_HEIGTH);
// 		// s_img.addr = mlx_get_data_addr(s_img.img_ptr, &s_img.bits_per_pixel, &s_img.line_len, &s_img.endian);
// 		// mlx_put_image_to_window(var.mlx->ptr, var.mlx->window, var.mlx->img, 0, 0);
// 		mlx_loop_hook(var.mlx->ptr, &render, &var.mlx);
// 		mlx_hook(var.mlx->window, 2, (1L << 0), &keypress, &var.mlx);
// 		// start(var.mlx);
// 		mlx_loop(var.mlx->ptr);
// 	}
// 	else
// 		write(2, "Error 2 arguments needed\n", 25);
// 	return (0);
// }

void	ft_assign(t_var *var)
{
	t_img	s_img;
	t_mlx	s_mlx;
	t_ray	s_ray;

	var->img = &s_img;
	var->mlx = &s_mlx;
	var->ray = &s_ray;
	var->ray->pos_x = 22;
	var->ray->pos_y = 12;
	var->ray->dir_x = -1;
	var->ray->dir_y = 0;
	var->ray->plane_x = 0;
	var->ray->plane_y = 0.66;
	var->ray->time = 0;
	var->ray->pv_time = 0;

}

void	ft_calc_ray_dir(t_var *var, char **map)
{
	int	x;
	int	w;
	int	h;


	w = MAP_WIDTH;
	h = MAP_HEIGTH;
	x = 0;
	while (x < w)
	{
		//calculates ray and direction position 
		//x coordinates in camera space
		var->ray->camera_x = (2 * x) / (double)w - 1;
		var->ray->raydir_x = var->ray->dir_x + var->ray->plane_x * var->ray->camera_x;
		var->ray->raydir_y = var->ray->dir_y + var->ray->plane_y * var->ray->camera_x;
		//which box of the map we're in
		var->ray->map_x = (int)var->ray->pos_x;
		var->ray->map_y = (int)var->ray->pos_y;
		//length of ray from one x or y side to next x or y side
		var->ray->deltadist_x = abs(1 / var->ray->raydir_x);
		var->ray->deltadist_y = abs(1 / var->ray->raydir_y);
		var->ray->hit = 0;
		//calculate step and initial sideDist
		if (var->ray->raydir_x < 0)
		{
			var->ray->step_x = -1;
			var->ray->sidedist_x = (var->ray->pos_x - var->ray->map_x) * var->ray->deltadist_x;
		}
		else
		{
			var->ray->step_x = 1;
			var->ray->sidedist_x = (var->ray->map_x + 1.0 - var->ray->pos_x) * var->ray->deltadist_x;
		}
		if (var->ray->raydir_y < 0)
		{
			var->ray->step_y = -1;
			var->ray->sidedist_y = (var->ray->pos_y - var->ray->map_y) * var->ray->deltadist_y;
		}
		else
		{
			var->ray->step_y = 1;
			var->ray->sidedist_y = (var->ray->map_y + 1.0 - var->ray->pos_y) * var->ray->deltadist_y;
		}
		//perform DDA
		while (var->ray->hit == 0)
		{
			//jump to next map square, either in x-direction or in y direction
			if (var->ray->sidedist_x < var->ray->sidedist_y)
			{
				var->ray->sidedist_x += var->ray->deltadist_x;
				var->ray->map_x += var->ray->step_x;
				var->ray->side = 0;
			}
			else
			{
				var->ray->sidedist_y = var->ray->deltadist_y;
				var->ray->map_y += var->ray->step_y;
				var->ray->side = 1;
			}
			if (map[var->ray->map_x][var->ray->map_y] > 0)
				var->ray->hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (var->ray->side == 0)
			var->ray->perpWallDist = (var->ray->sidedist_x - var->ray->deltadist_x);
		else
			var->ray->perpWallDist = (var->ray->sidedist_y - var->ray->deltadist_y);
		
		//Calculate height of line to draw on screen
		var->ray->lineHeight = (int)(h / var->ray->perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		var->ray->drawStart = -var->ray->lineHeight / 2 + h / 2;
		if (var->ray->drawStart < 0)
			var->ray->drawStart = 0;
		var->ray->drawEnd = var->ray->lineHeight / 2 + h / 2;
		if (var->ray->drawEnd >= h)
			var->ray->drawEnd = h - 1;
		//choose wall color
		x++;
	}
}

int main(int argc, char **argv)
{
	t_var	var;
	char *map[MAP_HEIGTH];
	map[0] = "1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1";
	map[1] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[2] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[3] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[4] = "1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1";
	map[5] = "1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[6] = "1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1";
	map[7] = "1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[8] = "1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1";
	map[9] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[10] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[11] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[12] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[13] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[14] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[15] = "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[16] = "1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[17] = "1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[18] = "1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[19] = "1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[20] = "1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[21] = "1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1";
	map[22] = "1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1";
	map[23] = NULL;
	(void)argc;
	(void)argv;
	ft_assign(&var);
	var.mlx->ptr = mlx_init();
	var.mlx->window = mlx_new_window(var.mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	while(1);
	
}