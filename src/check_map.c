/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:24:03 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 12:36:31 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	check_hor(t_var *var, char **map, int row, int col)
{
	if (map[row][col - 1] == ' ' || map[row][col + 1] == ' ')
		error_msg_exit(var, "invalid map layout");
}

static void	check_ver(t_var *var, char **map, int row, int col)
{
	if (map[row - 1][col] == ' ' || map[row + 1][col] == ' ')
		error_msg_exit(var, "invalid map layout");
}

static void	check_cross(t_var *var, char **map, int row, int col)
{
	if (ft_is_whitespace_char(map[row][col - 1]))
		error_msg_exit(var, "invalid map layout");
	if (ft_is_whitespace_char(map[row - 1][col]))
		error_msg_exit(var, "invalid map layout");
	if (ft_is_whitespace_char(map[row][col + 1]))
		error_msg_exit(var, "invalid map layout");
	if (ft_is_whitespace_char(map[row + 1][col]))
		error_msg_exit(var, "invalid map layout");
	if (map[row][col - 1] == '1')
		check_ver(var, map, row, col - 1);
	if (map[row][col + 1] == '1')
		check_ver(var, map, row, col + 1);
	if (map[row - 1][col] == '1')
		check_hor(var, map, row - 1, col);
	if (map[row + 1][col] == '1')
		check_hor(var, map, row + 1, col);
}

// checks validity of map
void	check_map(t_var *var)
{
	int	col;
	int	row;

	if (var->data->p_set == 0)
		error_msg_exit(var, "map error: no player found");
	row = 0;
	while (row < var->data->map_lines)
	{
		col = 0;
		while (col < var->data->map_col)
		{
			if (is_mchar(var->data->map[row][col]))
			{
				if (row == var->data->map_lines - 1 || row == 0 || \
				col == var->data->map_col - 1 || col == 0)
					error_msg_exit(var, "invalid map layout");
				check_cross(var, var->data->map, row, col);
			}
			col++;
		}
		row++;
	}
}
