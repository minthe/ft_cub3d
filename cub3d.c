/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:02 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/07 19:03:36 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

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
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void draw_line(t_var *var, int x, int color)
{
	int i;
	// int color;	
	i = -1;
	while (++i < var->ray->drawStart)
		img_pix_put(&var->img, x, i, color);
	//here suppose to be sky color later
	i = -1;
	while (++i < var->ray->drawEnd - var->ray->drawStart)
	{
		/// I'l put somewhere here texture later
		my_mlx_pixel_put(&var->img, x, var->ray->drawStart + i, color);
	}
	i = -1;
	while (++i < MAP_HEIGTH - var->ray->drawEnd)
		my_mlx_pixel_put(&var->img, x, var->ray->drawEnd, color);
		//here suppose to be floor color later
}
void	ft_calc_ray_dir(t_var *var, char **map)
{
	int	x;
	int	w;
	int	h;
	int color;


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
		if (map[var->ray->map_x][var->ray->map_y])
		{
			if (color == 0xFF0000)//red
				break ;
			if (color == 0x00FF00)//green
				break ;
			if (color == 0x0000FF)//blue
				break ;
			if (color == 0xFFFF00)//yellow
				break ;
			if (color == 0xFFFFFF)//white
				break ;
		}
		//give x and y sides different brightness
		if (var->ray->side == 1)
			color = color / 2;
		//draw the pixels of the stripe as a vertical line
		draw_line(var, x, color);
		//timing for input and fps counter
		var->ray->pv_time = var->ray->time;
		var->ray->time = time();// notgood
		var->ray->frametime = (var->ray->time - var->ray->pv_time) / 1000.0;
		print(1.0/var->ray->frametime);
		redra
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