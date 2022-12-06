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

// #include "inc/cub3d.h"

// void	mlx_pixl_put(t_var *var, int x, int y, int color)
// {
// 	char	*pixel;
// 	int		i;
// 	pixel = var->mlx->img->addr + (y * var->mlx->img->line_len + x * (var->mlx->img->bits_per_pixel / 8));
// 	// *(unsigned int*)pixel = color;
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit */
// 		if (var->mlx->img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit */
// 		else
// 			*pixel++ = (color >> (var->mlx->img->bits_per_pixel - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

// int	x_window(t_mlx *mlx)// need to free other stuff here later
// {
// 	write(1, "Exited the game\n", 16);
// 	// mlx_destroy_image(var->mlx->ptr, var->mlx->img->img_ptr);
// 	mlx_destroy_window(mlx->ptr, mlx->window);
// 	mlx->window = NULL;
// 	return (0);
// }

// void	ft_w(t_var *var)
// {
// 	var->posy -=5;
// 	// mlx_pixl_put(var, var->posx, var->posy, 0x00FF0000);	
// 	// mlx_clear_window(var->mlx->ptr, var->mlx->window);
// 	// mlx_destroy_image(var->mlx->ptr, var->mlx->img);
// 	// mlx_pixl_put(var, var->posx, var->posy, 0x00FF0000);
// 	// mlx_put_image_to_window(var->mlx->ptr, var->mlx->window, var->mlx->img, var->posx, var->posx);
// 	// mlx_put_image_to_window(data_m.ptr, data_m.window, data_m.img, 0, 0);
// }