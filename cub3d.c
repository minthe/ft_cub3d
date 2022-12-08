/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:02 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/07 19:23:37 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	keypress(int key, t_var *var)
{
	if (key == W)
		var->posy += 5;
	if (key == A)
		var->posx -= 5;
	if (key == S)
		var->posy -= 5;
	if (key == D)
		var->posy += 5;
}


// int	x_window(t_var *var)// need to free other stuff here later
// {
// 	write(1, "Exited the game\n", 16);
// 	mlx_destroy_window(var->mlx->ptr, var->mlx->window);
// 	free(var->mlx->ptr);
// 	exit(0);
// }

// void mlx_pixel_put()
// {
// }

// int	ft_loop(t_var *var)
// {
// 	var->player_pos[0] = var->posx;
// 	var->player_pos[1] = var->posy;
	
// }

// void	start(t_var *var)
// {
// 	mlx_hook(var->mlx->ptr, 17, 0L, x_window(var), var->mlx);
// 	mlx_loop_hook(var->mlx, ft_loop(var), var->mlx);
// }

int	main(int argc, char **argv)
{
	t_var	var;
	t_mlx	mlx_s;
	t_cub	cub_s;

	var.mlx = &mlx_s;
	var.cub = &cub_s;
	if (argc > 1 && init_struct(&var) && import_cub(&var, argv[1], ".cub"))
	{
		// mlx_s.ptr = mlx_init();
		// mlx_s.window = mlx_new_window(mlx_s.ptr, S_WIDTH, S_HEIGTH, "cub3d");
		// mlx_s.img = mlx_new_image(mlx_s.ptr, S_WIDTH, S_HEIGTH);
		// mlx_loop(mlx_s.ptr);
	}
	return (0);
}
