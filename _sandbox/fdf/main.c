/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:37:21 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/23 17:35:53 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// FdF "evaluated version"
int	main(int argc, char *argv[])
{
	t_fdf	data;

	if (argc != 2)
		return (0);
	data.map = argv[1];
	initialize_map(&data);
	fdf(&data);
	mlx_hook(data.win, 17, 0, close_fdf, &data);
	mlx_key_hook(data.win, key_cmd, &data);
	mlx_loop(data.mlx);
	return (0);
}
