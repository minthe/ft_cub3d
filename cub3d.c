/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:02 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/28 13:57:51 by vfuhlenb         ###   ########.fr       */
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
		printf("running...\n");
	}
	cleanup(&var);
	return (0);
}
