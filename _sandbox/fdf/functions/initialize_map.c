/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:37:51 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/22 12:22:29 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// parses data into struct and validates if map is rectangular
void	initialize_map(t_fdf *data)
{
	data->win_size_x = WIN_WIDTH;
	data->win_size_y = WIN_HEIGHT;
	data->height = NULL;
	data->mlx = mlx_init();
	data->image = ft_calloc(sizeof(t_image), 1);
	data->win = mlx_new_window(data->mlx, data->win_size_x, \
	data->win_size_y, "fdf");
	if (!data->mlx || !data->win || !data->image)
		exit_perror(NULL);
	data->image->img = mlx_new_image(data->mlx, data->win_size_x, \
	data->win_size_y);
	data->image->addr = mlx_get_data_addr(data->image->img, \
	&data->image->bits_per_pixel, \
	&data->image->line_length, &data->image->endian);
	data->lines = count_lines(data->map);
	if (data->lines < 1)
		error_msg(data, "-- Invalid Map --\n");
	data->colums = count_colums(data);
	data->height = (int **) ft_calloc(sizeof(int *), data->lines);
	if (data->height == NULL)
		return ;
	fills_grid(data);
}
