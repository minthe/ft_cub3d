/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:09:03 by dimbrea           #+#    #+#             */
/*   Updated: 2022/12/10 18:44:03 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	ft_draw_line(t_var *var, int start_x, int start_y, int end_x, int end_y, int color)
{
	double delta_x;
	double delta_y;
	double pixels_x;
	double pixels_y;
	int		pixels;


	delta_x = end_x - start_x;
	delta_y = end_y - start_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixels_x = start_x;
	pixels_y = start_y;
	while (pixels)
	{
		img_pix_put(var, pixels_x, pixels_y, color);
		pixels_x += delta_x;
		pixels_y += delta_y;
		--pixels;
	}
	return (0);
}

void	img_pix_put(t_var *var, int x, int y, int color)
{
	char	*pixel;

	pixel = var->img->addr + (y * var->img->size_line + x * (var->img->bpp / 8));
	*(int *)pixel = color;
}

int	x_window(t_var *var)// need to free other stuff here later
{
	write(1, "Exited the game\n", 16);
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	mlx_destroy_window(var->mlx->ptr, var->mlx->window);
	var->mlx->window = NULL;
	exit(0);
	return (0);
}

void	ft_w(t_var *var)
{
	var->plr->pos_y -=5;
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_player(var);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->structure, var->plr->pos_x, var->plr->pos_y);
}

void	ft_a(t_var *var)
{
	var->plr->pos_x -=5;
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_player(var);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->structure, var->plr->pos_x, var->plr->pos_y);
}

void	ft_s(t_var *var)
{
	var->plr->pos_y +=5;
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_player(var);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->structure, var->plr->pos_x, var->plr->pos_y);
}

void	ft_d(t_var *var)
{
	var->plr->pos_x +=5;
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_player(var);
	mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->img->structure, var->plr->pos_x, var->plr->pos_y);
}


void	render_background(t_var *var, int color)
{
	int	i;
	int	j;
	int	width;
	int	height;

	width = SCREEN_WIDTH/MAP_WIDTH;
	height = SCREEN_HEIGHT/MAP_HEIGHT;
	i = 0;
	j = 0;
	while (i <= SCREEN_HEIGHT)
	{
		if (j > SCREEN_WIDTH)
			break;
		img_pix_put(var->img->structure, j, i, color);
		if (i == SCREEN_HEIGHT)
		{
			i = 0;
			j += width;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i <= SCREEN_WIDTH)
	{
		if (j > SCREEN_HEIGHT)
			break;
		img_pix_put(var->img->structure, i, j, color);
		if (i == SCREEN_WIDTH)
		{
			i = 0;
			j += height;
		}
		i++;
	}
	i = SCREEN_HEIGHT - 1;
	j = 0;
	while (j <= SCREEN_WIDTH)
	{
		img_pix_put(var->img->structure, j, i, color);
		j++;
	}
}