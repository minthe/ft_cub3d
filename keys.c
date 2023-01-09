/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:09:03 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/09 15:45:00 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

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
	if (!ft_is_wall(var, var->plr->pos_x, var->plr->pos_y - 5))
	{
		var->plr->pos_y -= 5;
		var->plr->end_y -= 5;
	}
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	ft_a(t_var *var)
{
	if (!ft_is_wall(var, var->plr->pos_x - 5, var->plr->pos_y))
	{
		var->plr->pos_x -= 5;
		var->plr->end_x -= 5;
	}
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	ft_s(t_var *var)
{
	if (!ft_is_wall(var, var->plr->pos_x, var->plr->pos_y + 5))
	{
		var->plr->pos_y += 5;
		var->plr->end_y += 5;
	}
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	ft_d(t_var *var)
{
	if (!ft_is_wall(var, var->plr->pos_x + 5, var->plr->pos_y))
	{
		var->plr->pos_x += 5;
		var->plr->end_x += 5;
	}
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

// void	ft_arrow(t_var *var)
// {
// 	double radians;
// 	double line_l;

// 	if (var->plr->p_angle >= 360.0)
// 		var->plr->p_angle = 0.0;
// 	line_l = sqrt((var->plr->end_x - var->plr->pos_x) * (var->plr->end_x - var->plr->pos_x) + (var->plr->end_y - var->plr->pos_y) * (var->plr->end_y - var->plr->pos_y));
// 	printf("%f angle_r ARROW\n", var->plr->p_angle);
// 	var->plr->p_angle += 10;
// 	radians = var->plr->p_angle * M_PI /180;
// 	printf("%f angle\n", radians);
// 	var->plr->end_x = var->plr->pos_x + line_l * cos(radians);
// 	var->plr->end_y = var->plr->pos_y + line_l * sin(radians);
// 	mlx_destroy_image(var->mlx->ptr, var->img->structure);
// 	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
// }

//casts an arrow (the "view" of the player) line_l is the line of the arrow and
//is calculated with that formula
//we convert the p_angle to radians using (angle * PI / 180) formula
void	ft_arrow(t_var *var, int arrow)
{
	// double radians;
	double line_l;
	
	if (var->plr->p_angle >= 360.0 || var->plr->p_angle <= -360.0)
		var->plr->p_angle = 0.0;
	line_l = sqrt((var->plr->end_x - var->plr->pos_x) * (var->plr->end_x - var->plr->pos_x) + (var->plr->end_y - var->plr->pos_y) * (var->plr->end_y - var->plr->pos_y));
	if (arrow == L_ARROW)
		var->plr->p_angle += 10;
	else
		var->plr->p_angle -= 10;
	var->plr->radians = var->plr->p_angle * M_PI /180;
	var->plr->end_x = var->plr->pos_x + line_l * cos(-var->plr->radians);
	var->plr->end_y = var->plr->pos_y + line_l * sin(-var->plr->radians);
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	render_background(t_var *var)
{
	int	i;
	int	j;
	int color;

	color = 0xFFFFFF;
	i = 0;
	j = 0;
	while (i <= SCREEN_HEIGHT)
	{
		if (j > SCREEN_WIDTH)
			break;
		img_pix_put(var, j, i, color);
		if (i == SCREEN_HEIGHT)
		{
			i = 0;
			j += var->map->modul_w;
		}
		i++;
	}
	i = 0;
	j = SCREEN_WIDTH - 1; 
	while (i <= SCREEN_HEIGHT)
	{
		img_pix_put(var, j, i, color);
		i++;
	}
	i = 0;
	j = 0;
	while (i <= SCREEN_WIDTH)
	{
		if (j > SCREEN_HEIGHT)
			break;
		img_pix_put(var, i, j, color);
		if (i == SCREEN_WIDTH)
		{
			i = 0;
			j += var->map->modul_h;
		}
		i++;
	}
	i = SCREEN_HEIGHT - 1;
	j = 0;
	while (j <= SCREEN_WIDTH)
	{
		img_pix_put(var, j, i, color);
		j++;
	}
}
