/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:24:03 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/15 20:15:04 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_hor(char **map, int row, int col)
{
	if (map[row][col - 1] == ' ' || map[row][col + 1] == ' ')
		error_msg_exit("invalid map layout");
}

static void	check_ver(char **map, int row, int col)
{
	if (map[row - 1][col] == ' ' || map[row + 1][col] == ' ')
		error_msg_exit("invalid map layout");
}

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
	if (map[row][col - 1] == '1')
		check_ver(map, row, col - 1);
	if (map[row][col + 1] == '1')
		check_ver(map, row, col + 1);
	if (map[row - 1][col] == '1')
		check_hor(map, row - 1, col);
	if (map[row + 1][col] == '1')
		check_hor(map, row + 1, col);
}

// checks validity of map
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
