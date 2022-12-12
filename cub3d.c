/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:02 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 13:13:34 by vfuhlenb         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_mlx	mlx_s;
	t_data	cub_s;
	t_var	var;

	var.data = &cub_s;
	var.mlx = &mlx_s;
	if (argc > 1 && init_struct(&var) && import_cub(&var, argv[1], ".cub"))
	{
		// mlx_s.ptr = mlx_init();
		// mlx_s.window = mlx_new_window(mlx_s.ptr, S_WIDTH, S_HEIGTH, "cub3d");
		// mlx_s.img = mlx_new_image(mlx_s.ptr, S_WIDTH, S_HEIGTH);
		// mlx_loop(mlx_s.ptr);
	}
	return (0);
}
