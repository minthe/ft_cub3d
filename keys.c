// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   keys.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/04 17:09:03 by dimbrea           #+#    #+#             */
// /*   Updated: 2022/12/05 17:48:09 by dimbrea          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "inc/cub3d.h"

void	ft_pixl_put(t_var *var, int x, int y, int color)
{
	char	*pixel;
	int		i;

	pixel = var->img->addr + (y * var->img->line_len + x * (var->img->bpp / 8));
	i = var->img->bpp -8;
	while (i >= 0)
	{
		if (var->img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (var->img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	x_window(t_var *var)// need to free other stuff here later
{
	write(1, "Exited the game\n", 16);
	// mlx_destroy_image(var->mlx->ptr, var->mlx->img->img_ptr);
	mlx_destroy_window(var->mlx->ptr, var->mlx->window);
	var->mlx->window = NULL;
	exit(0);
	return (0);
}

void	ft_w(t_var *var)
{
	var->plr->pos_y -=5;
	mlx_clear_window(var->mlx->ptr, var->mlx->window);
	mlx_pixel_put(var->mlx->ptr, var->mlx->window, var->plr->pos_x, var->plr->pos_y, 0xFF0000);
}

void	ft_a(t_var *var)
{
	var->plr->pos_x -= 5;
	mlx_clear_window(var->mlx->ptr, var->mlx->window);
	mlx_pixel_put(var->mlx->ptr, var->mlx->window, var->plr->pos_x, var->plr->pos_y, 0xFF0000);
}

void	ft_s(t_var *var)
{
	var->plr->pos_y += 5;
	mlx_clear_window(var->mlx->ptr, var->mlx->window);
	mlx_pixel_put(var->mlx->ptr, var->mlx->window, var->plr->pos_x, var->plr->pos_y, 0xFF0000);
}

void	ft_d(t_var *var)
{
	var->plr->pos_x += 5;
	mlx_clear_window(var->mlx->ptr, var->mlx->window);
	mlx_pixel_put(var->mlx->ptr, var->mlx->window, var->plr->pos_x, var->plr->pos_y, 0xFF0000);
}