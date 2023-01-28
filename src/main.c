/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:03:45 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/28 14:44:02 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	ft_init_struct(t_var *var)
{
	var->mlx = malloc(sizeof(t_mlx));
	var->map = malloc(sizeof(t_map));
	var->img = malloc(sizeof(t_img));
	var->plr = malloc(sizeof(t_player));
	var->txt = malloc(sizeof(t_txt));
	var->data = malloc(sizeof(t_data));
}

void	ft_free_struct(t_var *var)
{
	free(var->mlx);
	free(var->map);
	free(var->img);
	free(var->plr);
	free(var->txt);
}

void	ft_mlx_loops(t_var *var)
{
	mlx_hook(var->mlx->window, 17, 0L, x_window, var);
	mlx_hook(var->mlx->window, 2, (1l << 0), keypress, var);
	mlx_loop_hook(var->mlx->ptr, &render, var);
	mlx_loop(var->mlx->ptr);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc == 2)
	{
		var = malloc(sizeof(t_var));
		ft_init_struct(var);
		if (init_struct(var) && import_cub(var, argv[1], ".cub"))
		{
			ft_map_size(var);
			ft_put_player(var);
			var->mlx->ptr = mlx_init();
			var->mlx->window = mlx_new_window(var->mlx->ptr, \
						SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
			var->img->structure = mlx_new_image(var->mlx->ptr, \
						SCREEN_WIDTH, SCREEN_HEIGHT);
			var->img->addr = mlx_get_data_addr(var->img->structure, \
				&var->img->bpp, &var->img->size_line, &var->img->endian);
			ft_ray(var, var->plr->orient);
			ft_mlx_loops(var);
		}
		cleanup(var);
	}
	else
		error_msg("Only one argument allowed (map)");
	return (0);
}
