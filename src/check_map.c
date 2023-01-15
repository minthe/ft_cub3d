/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:24:03 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/15 15:04:18 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_cross(char **map, int row, int col)
{
	if (ft_is_whitespace_char(map[row][col - 1]))
		error_msg_exit("invalid map layout");
	if (ft_is_whitespace_char(map[row - 1][col]))
		error_msg_exit("invalid map layout");
	if (ft_is_whitespace_char(map[row][col + 1]))
		error_msg_exit("invalid map layout");
	if (ft_is_whitespace_char(map[row + 1][col]))
		error_msg_exit("invalid map layout");
}

void	check_map(t_data *data)
{
	int	col;
	int	row;

	if (!data->p_set)
		error_msg_exit("map error: no player found");
	row = 0;
	while (row < data->map_lines)
	{
		col = 0;
		while (col < data->map_col)
		{
			if (is_mchar(data->map[row][col]))
			{
				if (row == data->map_lines - 1 || row == 0 || \
				col == data->map_col - 1 || col == 0)
					error_msg_exit("invalid map layout");
				check_cross(data->map, row, col);
			}
			col++;
		}
		row++;
	}
}
