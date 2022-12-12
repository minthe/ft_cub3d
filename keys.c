/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:09:03 by dimbrea           #+#    #+#             */
/*   Updated: 2022/12/12 17:56:20 by dimbrea          ###   ########.fr       */
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
		var->plr->pos_y -= 5;
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	ft_a(t_var *var)
{
	if (!ft_is_wall(var, var->plr->pos_x - 5, var->plr->pos_y))
		var->plr->pos_x -= 5;
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	ft_s(t_var *var)
{
	if (!ft_is_wall(var, var->plr->pos_x, var->plr->pos_y + 5))
		var->plr->pos_y += 5;
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	var->img->structure = mlx_new_image(var->mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	ft_d(t_var *var)
{
	if (!ft_is_wall(var, var->plr->pos_x + 5, var->plr->pos_y))
		var->plr->pos_x += 5;
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
